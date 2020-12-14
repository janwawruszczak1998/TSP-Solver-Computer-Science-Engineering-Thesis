#ifndef RANDOMS_H
#define RANDOMS_H

#include <cstdlib>
#include <cmath>
#include <limits>
#include <random>

namespace re {
    class Randoms {

    public:

        Randoms() = default;

        double uniform();

        int random_in_range(int, int);
    private:
        std::random_device rand_device;

    };
} // namespace re;

#endif // RANDOMS_H
