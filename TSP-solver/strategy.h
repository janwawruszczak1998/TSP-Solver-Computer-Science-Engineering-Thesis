#ifndef STRATEGY_H
#define STRATEGY_H

#include <vector>
#include <thread>

#include "Graph.hpp"
#include "randoms.h"
#include "mutex"


class Strategy
{
public:
    Strategy(tsp::Graph<double, std::vector> &, unsigned&, std::vector<unsigned>&);
    virtual ~Strategy();

    virtual void calculate_solution() = 0;

    std::thread& get_algo_thread();
    double random_path(std::vector<unsigned> &, tsp::Graph<double, std::vector> &);
    double calculate_objective(std::vector<unsigned> &permutation, tsp::Graph<double, std::vector> &);

protected:
    std::thread algo_thread{};
    std::mutex result_mutex{};

    tsp::Graph<double, std::vector> &graph;
    unsigned& result___;
    std::vector<unsigned>& route___;
    re::Randoms randoms;

};

#endif // STRATEGY_H
