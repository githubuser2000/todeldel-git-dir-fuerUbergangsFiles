#include "rational.hpp"
#include <vector>

std::vector<Rational> randomTriplet(std::size_t n) {
    std::vector<Rational> v;
    v.reserve(n);

    for (std::size_t i = 0; i < n; ++i) {
        v.emplace_back(i + 1, 1); // placeholder Rational(i+1,1)
    }

    return v;
}
