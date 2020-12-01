#ifndef STRATEGY_H
#define STRATEGY_H

#include <vector>
#include <thread>

#include "Graph.hpp"

class Strategy
{
public:
    Strategy(tsp::Graph<double, std::vector> &, unsigned&);
    virtual ~Strategy();

    virtual void calculate_solution() = 0;

    std::thread& get_algo_thread();
    unsigned random_path(std::vector<unsigned> &, std::unique_ptr <tsp::Graph<double, std::vector>> &);
    unsigned calculate_objective(std::vector<unsigned> &permutation, std::unique_ptr <tsp::Graph<double, std::vector>> &);

protected:
    static int solution_cost;
    static std::vector<int> solution;
    std::thread algo_thread;

    tsp::Graph<double, std::vector> &graph;
    unsigned& result;
};

#endif // STRATEGY_H
