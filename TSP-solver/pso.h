#ifndef PSO_H
#define PSO_H


#include "strategy.h"

class PSO: public Strategy
{
public:
    PSO(tsp::Graph<double, std::vector> &, unsigned&);
    ~PSO();

    void calculate_solution() override;
};
#endif // PSO_H
