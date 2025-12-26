// -*- coding: utf-8 -*-
#include "rational.h"

Rational randomRational(int min, int max) {
    static std::mt19937 rng{std::random_device{}()};
    std::uniform_int_distribution<int> dist(min, max);
    return Rational{dist(rng), dist(rng)};
}

std::size_t randomLength(std::size_t min, std::size_t max) {
    static std::mt19937 rng{std::random_device{}()};
    std::uniform_int_distribution<std::size_t> dist(min, max);
    return dist(rng);
}

std::vector<Rational> randomTriplet(std::size_t n) {
    std::vector<Rational> v;
    v.reserve(n);
    for (std::size_t i = 0; i < n; ++i)
        v.push_back(randomRational());
    return v;
}
