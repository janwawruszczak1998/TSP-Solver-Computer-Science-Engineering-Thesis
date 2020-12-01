#include "strategy.h"
#include <thread>

Strategy::Strategy(tsp::Graph<double, std::vector>& graph_, unsigned& result_)
:
graph{graph_},
result{result_}
{
}

Strategy::~Strategy(){
}

std::thread& Strategy::get_algo_thread(){
    return algo_thread;
}

unsigned Strategy::random_path(std::vector<unsigned> &v, std::unique_ptr <tsp::Graph<double, std::vector>> &g) {

    v.clear();
    v.reserve(g->get_order());
    for (unsigned i = 0; i < g->get_order(); ++i) {
        v.push_back(i);
    }

    std::random_shuffle(v.begin(), v.end());
    return calculate_objective(v, g);

}

unsigned calculate_objective(std::vector<unsigned> &permutation, std::unique_ptr <tsp::Graph<double, std::vector>> &g) {
    unsigned result = 0;

    for (auto it = permutation.cbegin(); it + 1 != permutation.cend(); ++it) {
        result += g->get_distance(*it, *(it+1));

    }

    result += g->get_distance(*(permutation.end() - 1), *(permutation.begin()));
    return result;

}
