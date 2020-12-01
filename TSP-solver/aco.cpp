#include "aco.h"
#include "strategy.h"
#include <thread>

ACO::ACO(tsp::Graph<double, std::vector>& graph_, unsigned& result_) : Strategy(graph_, result_)
{
    algo_thread = std::thread{[this](){this->calculate_solution();}};
}

ACO::~ACO(){

}

void ACO::calculate_solution() {
    result = 15;
}
