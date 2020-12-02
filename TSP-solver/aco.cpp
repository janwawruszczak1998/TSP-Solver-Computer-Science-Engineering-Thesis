#include "aco.h"
#include "strategy.h"
#include <thread>

ACO::ACO(tsp::Graph<double, std::vector>& graph_, unsigned& result_, std::vector<unsigned>& route_)
: Strategy(graph_, result_, route_)
{
    algo_thread = std::thread{[this](){this->calculate_solution();}};
}

ACO::~ACO(){

}

void ACO::calculate_solution() {
        unsigned best = 1e9;
        unsigned iterations = 100;
        unsigned numOfAnts = graph.get_order();

        //trasy mrowek
        std::vector <std::vector<unsigned>> routes(numOfAnts);
        for (unsigned i = 0; i < graph.get_order(); ++i) {
            routes[i].resize(graph.get_order());
        }
        //feromony na krawedziach
        std::vector <std::vector<double>> pheromones(graph.get_order());
        for (unsigned i = 0; i < graph.get_order(); ++i) {
            pheromones[i].resize(graph.get_order());
            for (unsigned j = 0; j < graph.get_order(); ++j) {
                pheromones[i][j] =
                        randoms.uniform() * graph.get_order() / graph.get_distance(0, 1);  //losowa ilość feromonu na krawędziach
            }
        }


        //wielokrotne puszczenie mrowek
        for (unsigned i = 0; i < iterations; ++i) {
            //czyszczenie starych tras
            for (unsigned ant = 0; ant < numOfAnts; ++ant) {
                for (auto &route : routes[ant]) {
                    route = -1;
                }
                //stworzenie mrowki i puszczenie jej w trase
                Ant *next_ant = new Ant(ant, graph.get_order());
                route(next_ant, routes, graph, pheromones);

            }

            //akutalizacja feromonow
            update_pheromones(pheromones, routes, graph);

            //wyczyszczenie tras
            for (unsigned a = 0; a < graph.get_order(); ++a) {
                if (route_value(routes[a], graph) < best) {
                    best = route_value(routes[a], graph);
                    {
                        std::lock_guard<std::mutex> lock(result_mutex);
                        if(result___ > best){
                            result___ = best;
                            route___ = routes[a];
                        }
                    }
                }
                for (unsigned b = 0; b < graph.get_order(); ++b)
                    routes[a][b] = -1;
            }

        }

        std::cout << "Najlepsze co znalazly mrowki to: " << best << std::endl;
}

double ACO::Phi(unsigned city_i, unsigned city_j, ACO::Ant *ant, tsp::Graph<double, std::vector>& graph,
           std::vector <std::vector<double>> &pheromones) {
    double A = 1.1, B = 4.5;

    auto eta_ij = pow( static_cast<double>(1.0 / graph.get_distance(city_i, city_j)), B);
    auto tau_ij = pow(pheromones[city_i][city_j], A);
    auto sum = 0.0;

    //obliczenie sumy dla pozostalych miast
    for (unsigned i = 0; i < graph.get_order(); ++i) {
        if (i == city_i) continue;   //nie rozwazamy przejscia do samego siebie
        if (!ant->get_ant_tabu()[i]) {
            auto eta = pow( static_cast<double>(1.0 / graph.get_distance(city_i, i)), B);
            auto tau = pow(pheromones[city_i][i], A);
            sum += eta * tau;
        }
    }

    return (eta_ij * tau_ij) / sum;
}

unsigned ACO::route_value(std::vector<unsigned> &permutation, tsp::Graph<double, std::vector>& graph) {
    unsigned result = 0;

    for (auto it = permutation.cbegin(); it + 1 != permutation.cend(); ++it) {
        result += graph.get_distance(*it,*(it + 1));

    }

    result += graph.get_distance(*(permutation.end() - 1),*(permutation.begin()));
    return result;

}

void ACO::update_pheromones(std::vector <std::vector<double>> &pheromones, std::vector <std::vector<unsigned>> &routes,
                       tsp::Graph<double, std::vector>& graph) {
    double q = static_cast<double>(graph.get_order()); //parametr feromonowy - reguluje ile jest kladzione feromonu
    double ro = 0.5; //ro - parametr aktualizowanego feromonu < 1
    for (unsigned i = 0; i < routes.size(); ++i) {
        unsigned route_i = route_value(routes[i], graph); //obliczenie wartosci i-tej trasy
        for (unsigned j = 0; j < routes.size() - 1; ++j) {
            unsigned city_i = routes[i][j];
            unsigned city_j = routes[i][j + 1];
            pheromones[city_i][city_j] = (1.0 - ro) * pheromones[city_i][city_j] + q / (double) route_i;
            pheromones[city_j][city_i] = (1.0 - ro) * pheromones[city_j][city_i] + q / (double) route_i;
        }
    }
}

unsigned ACO::getNextCity(std::vector<double> &probability) {

    double xi = randoms.uniform();
    unsigned i = 0;
    double sum = probability[i];
    while (sum < xi) {
        i++;
        sum += probability[i];
    }

    return i;
}


void ACO::route(ACO::Ant *ant, std::vector <std::vector<unsigned>> &routes, tsp::Graph<double, std::vector>& graph,
           std::vector <std::vector<double>> &pheromones) {

    std::vector<double> probability; //vector prawodpodobienstw przejsc do miast

    routes[ant->get_number()][0] = ant->get_number();   //miasto poczatkowe mrowki to jej numer
    ant->get_ant_tabu()[ant->get_number()] = true;
    //ustalenie kolejnych n-1 miast trasy
    for (unsigned i = 0; i < graph.get_order() - 1; ++i) {
        unsigned city_i = routes[ant->get_number()][i];  //miasto i-te
        probability.clear();
        probability.resize(graph.get_order(), 0.0);

        //wylicz prawdopodobienswo przejscia do miasta j-tego
        for (unsigned city_j = 0; city_j < graph.get_order(); ++city_j) {
            if (city_i == city_j) continue;  //polaczenie ze samym soba
            if (!ant->get_ant_tabu()[city_j]) {   //jesli miasto jeszcze nie odwiedzone
                probability[city_j] = Phi(city_i, city_j, ant, graph, pheromones);
            }
        }


        //ustalenie kolejnego miasta
        routes[ant->get_number()][i + 1] = getNextCity(probability);
        ant->get_ant_tabu()[routes[ant->get_number()][i + 1]] = true;
    }
}




ACO::Ant::Ant(unsigned number_, unsigned n)
: number(number_){
    tabu.resize(n, false);
}

unsigned ACO::Ant::get_number() {
    return number;
}

std::vector<bool>& ACO::Ant::get_ant_tabu(){
    return tabu;
}
