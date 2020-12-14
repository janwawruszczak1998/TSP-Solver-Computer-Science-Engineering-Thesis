//biblioteka do losowan
#include <cstdlib>
#include <cmath>
#include <limits>
#include <random>
#include "randoms.h"


using namespace re;


double Randoms::uniform() {
    std::uniform_real_distribution<> dist(0, 1);
    std::mt19937 engine(rand_device());
    return dist(engine);
}

int Randoms::random_in_range(int min, int max) {
    static std::mt19937 mt(rand_device());
    static std::uniform_int_distribution<int> pick;

    return pick(mt, decltype(pick)::param_type{min, max});
}

