#ifndef ACO_H
#define ACO_H

#include "strategy.h"

class ACO: public Strategy
{
public:
    ACO(tsp::Graph<double, std::vector> &, unsigned&, std::vector<unsigned>&);
    ~ACO();

    void calculate_solution() override;

    class Ant {
    public:
        Ant(unsigned, unsigned);

        unsigned get_number();

        std::vector<bool> &get_ant_tabu();

    private:
        unsigned number;
        std::vector<bool> tabu;
    };

protected:
    void calculate_route(Ant *, std::vector<std::vector<unsigned> > &,tsp::Graph<double, std::vector> &, std::vector<std::vector<double> > &);
    double Phi(unsigned, unsigned, Ant *, tsp::Graph<double, std::vector> &, std::vector<std::vector<double> > &);
    unsigned getNextCity(std::vector<double> &);
    void update_pheromones(std::vector<std::vector<double>> &, std::vector <std::vector<unsigned>> &, tsp::Graph<double, std::vector>&);
    unsigned route_value(std::vector<unsigned> &, tsp::Graph<double, std::vector> &);
    void route(Ant *ant, std::vector <std::vector<unsigned>> &, tsp::Graph<double, std::vector> &, std::vector <std::vector<double>> &);
};

#endif // ACO_H
