#include "pso.h"
#include "strategy.h"
#include <thread>

PSO::PSO(tsp::Graph<double, std::vector>& graph_, unsigned& result_,std::vector<unsigned>& route_) : Strategy(graph_, result_, route_)
{
    algo_thread = std::thread{[this](){this->calculate_solution();}};
}

PSO::~PSO(){

}

void PSO::calculate_solution() {
    result___ = 20;
}
