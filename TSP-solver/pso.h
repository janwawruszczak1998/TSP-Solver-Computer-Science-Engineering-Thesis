#ifndef PSO_H
#define PSO_H


#include "strategy.h"

class PSO: public Strategy
{
public:
    PSO(tsp::Graph<double, std::vector> &, unsigned&, std::vector<unsigned>&);
    ~PSO();

    class Particle{
    public:
        Particle();
        Particle(double, double, double);
        ~Particle();
        void move_to_next_solution();
        void calculate_new_velocity();

        class Velocity{
        public:
            Velocity();
            Velocity(const Velocity &);
            Velocity(std::vector<unsigned> from_, std::vector<unsigned> to_);

            Velocity& operator=(const Velocity &);
            Velocity& operator*=(const double);
            Velocity& operator+=(const Velocity &);
            Velocity operator*(const double);
            Velocity operator+(const Velocity &);

            void add(unsigned, unsigned);
            void remove(unsigned);

            unsigned size{0};
            std::vector<unsigned> from{}, to{};
        };

        static double global_best;
        double personal_best{1e9};
        std::vector<unsigned> particle_solution;
        std::vector<unsigned> personal_best_solution;
        static std::vector<unsigned> global_solution;
        Velocity particle_velocity{};
        double alpha{}, beta{}, gamma{};

    };

    std::vector<Particle> swarm;
    void calculate_solution() override;



};
#endif // PSO_H
