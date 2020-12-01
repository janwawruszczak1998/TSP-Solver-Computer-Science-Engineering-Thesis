#ifndef ACO_H
#define ACO_H

#include "strategy.h"

class ACO: public Strategy
{
public:
    ACO(tsp::Graph<double, std::vector> &, unsigned&);
    ~ACO();

    void calculate_solution() override;
};

#endif // ACO_H
