#ifndef SA_H
#define SA_H

#include "strategy.h"

class SA: public Strategy
{
public:
    SA(tsp::Graph<double, std::vector> &, unsigned&);
    ~SA();

    void calculate_solution() override;
};

#endif // SA_H
