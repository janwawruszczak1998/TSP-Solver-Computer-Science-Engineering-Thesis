#ifndef DP_H
#define DP_H

#include "strategy.h"

class DP: public Strategy
{
public:
    DP(tsp::Graph<double, std::vector> &, unsigned&);
    ~DP();

    void calculate_solution() override;
};

#endif // DP_H
