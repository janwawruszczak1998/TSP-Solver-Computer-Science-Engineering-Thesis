#ifndef SA_H
#define SA_H

#include "strategy.h"

class SA : public Strategy {
public:
    SA(tsp::Graph<double, std::vector> &, unsigned &, std::vector<unsigned> &);

    ~SA();

    void calculate_solution() override;

protected:
    double cooling(double);

    double get_probability(unsigned, double);
};

#endif // SA_H
