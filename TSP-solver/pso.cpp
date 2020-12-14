#include "pso.h"
#include "strategy.h"
#include <thread>
#include <mutex>

#include <iostream>

//pso class
PSO::PSO(tsp::Graph<double, std::vector> &graph_, unsigned &result_, std::vector<unsigned> &route_) : Strategy(graph_,
                                                                                                               result_,
                                                                                                               route_) {
    run_flag = true;
    algo_thread = std::thread{[this]() { this->calculate_solution(); }};
}

PSO::~PSO() {
}

void PSO::calculate_solution() {
    for (unsigned i = 0; i < graph.get_order() * graph.get_order(); ++i) {
        swarm.push_back(Particle(0.3, 0.2, 0.5));
        swarm[i].particle_solution.resize(graph.get_order());
        for (unsigned j = 0; j < graph.get_order(); ++j) {
            swarm[i].particle_solution[j] = j;
        }
        std::random_shuffle(swarm[i].particle_solution.begin(), swarm[i].particle_solution.end());
        double move_value = calculate_objective(swarm[i].particle_solution, graph);
        swarm[i].personal_best = move_value;
        std::lock_guard <std::mutex> lock(result_mutex);
        if (Particle::global_best > move_value) {
            Particle::global_best = move_value;
            Particle::global_solution = swarm[i].particle_solution;
        }
    }
    while (run_flag) {
        for (auto &particle : swarm) {
            particle.calculate_new_velocity();
            particle.move_to_next_solution();

            double move_value = calculate_objective(particle.particle_solution, graph);
            if (particle.personal_best > move_value) {
                particle.personal_best = move_value;
            }
        }
        for (auto &particle : swarm) {
            std::lock_guard <std::mutex> lock(result_mutex);
            if (Particle::global_best > particle.personal_best) {
                Particle::global_best = particle.personal_best;
                Particle::global_solution = particle.particle_solution;
            }
            if (result___ > Particle::global_best) {
                result___ = Particle::global_best;
                route___ = particle.particle_solution;
            }
        }
    }
    std::cout << "BEST OF PSO " << Particle::global_best << std::endl;
}


// particle class
double PSO::Particle::global_best = 1e9;
std::vector<unsigned> PSO::Particle::global_solution = {};

PSO::Particle::Particle() {
    personal_best = 1e9;
}

PSO::Particle::Particle(double alpha_, double beta_, double gamma_)
        : alpha{alpha_}, beta{beta_}, gamma{gamma_} {
    global_best = global_best == 1e9 ? 1e9 : global_best;
    personal_best = 1e9;
}

PSO::Particle::~Particle() {
    global_best = 1e9;
}

void PSO::Particle::move_to_next_solution() {

    for (unsigned i = 0; i < particle_velocity.size; ++i) {
        unsigned tmp = particle_solution[particle_velocity.from[i]];
        particle_solution[particle_velocity.from[i]] = particle_solution[particle_velocity.to[i]];
        particle_solution[particle_velocity.to[i]] = tmp;
    }
}

void PSO::Particle::calculate_new_velocity() {
    // jak bardzo chcemy utrzymac aktualny kierunek
    Velocity a;
    if (particle_velocity.size > 0) {
        a = particle_velocity * alpha;
    }

    // wplyw swojego najlepszemu
    Velocity b_difference;
    std::vector<unsigned> tmp_solution(particle_solution);
    for (unsigned i = 0; i < global_solution.size(); ++i) {
        unsigned vertex = global_solution[i];
        unsigned found_index = global_solution.size();
        for (unsigned j = 0; j < tmp_solution.size(); ++j) {
            if (tmp_solution[j] == vertex) {
                found_index = j;
                unsigned tmp = particle_solution[i];
                tmp_solution[i] = tmp_solution[j];
                tmp_solution[j] = tmp;
                break;
            }
        }
        if (i != found_index && found_index != particle_solution.size()) {
            b_difference.add(i, found_index);
        }
    }

    Velocity b = b_difference * beta;

    // wplyw najlepszego wspolnego
    Velocity c_difference;
    tmp_solution = particle_solution;
    for (unsigned i = 0; i < personal_best_solution.size(); ++i) {
        unsigned vertex = personal_best_solution[i];
        unsigned found_index = personal_best_solution.size();
        for (unsigned j = 0; j < tmp_solution.size(); ++j) {
            if (tmp_solution[j] == vertex) {
                found_index = j;
                unsigned tmp = particle_solution[i];
                tmp_solution[i] = tmp_solution[j];
                tmp_solution[j] = tmp;
                break;
            }
        }

        if (i != found_index && found_index != particle_solution.size()) {
            c_difference.add(i, found_index);
        }
    }

    Velocity c = c_difference * gamma;
    particle_velocity = Velocity(a + b + c);
}


// velocity class
PSO::Particle::Velocity::Velocity() {

}

PSO::Particle::Velocity::Velocity(const Velocity &c_velocity) {
    size = 0;
    for (unsigned i = 0; i < c_velocity.size; ++i) {
        add(c_velocity.from[i], c_velocity.to[i]);
    }
}

PSO::Particle::Velocity::Velocity(std::vector<unsigned> from_, std::vector<unsigned> to_) {
    size = 0;
    for (unsigned i = 0; i < from_.size(); ++i) {
        add(from_[i], to_[i]);
    }
}

PSO::Particle::Velocity &PSO::Particle::Velocity::operator=(const Velocity &rhs) {
    if (this != &rhs) {
        from.clear();
        to.clear();
        size = 0;
    }
    for (unsigned i = 0; i < rhs.size; ++i) {
        add(rhs.from[i], rhs.to[i]);
    }

    return *this;
}

PSO::Particle::Velocity &PSO::Particle::Velocity::operator+=(const Velocity &rhs) {
    for (unsigned i = 0; i < rhs.size; ++i) {
        add(rhs.from[i], rhs.to[i]);
    }
    return *this;
}

PSO::Particle::Velocity PSO::Particle::Velocity::operator+(const Velocity &rhs) {
    Velocity ret_velocity(*this);
    ret_velocity += rhs;
    return ret_velocity;
}

PSO::Particle::Velocity &PSO::Particle::Velocity::operator*=(double d) {
    std::vector<unsigned> from(this->from);
    std::vector<unsigned> to(this->to);
    unsigned size{this->size};
    this->from.clear();
    this->to.clear();
    this->size = 0;


    while (d >= 2) {
        for (unsigned i = 0; i < size; ++i) {
            add(from[i], to[i]);
        }
        --d;
    }
    if (d >= 1) {
        --d;
    }
    if (d > 0) {
        unsigned cv = ceil(d * size);
        for (unsigned i = 0; i < cv; ++i) {
            add(from[i], to[i]);
        }
    }
    return *this;
}


PSO::Particle::Velocity PSO::Particle::Velocity::operator*(double rhs) {
    Velocity ret_velocity(*this);
    ret_velocity *= rhs;
    return ret_velocity;
}

void PSO::Particle::Velocity::add(unsigned a, unsigned b) {
    ++size;
    from.push_back(a);
    to.push_back(b);
}


void PSO::Particle::Velocity::remove(unsigned index) {
    --size;
    from.erase(from.begin() + index);
    to.erase(to.begin() + index);
}
