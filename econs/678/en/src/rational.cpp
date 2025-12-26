#include "rational.h"
#include <random>
#include <numeric>
#include <stdexcept>

static std::mt19937& rng() {
    static std::mt19937 g{std::random_device{}()};
    return g;
}

int randInt(int a, int b) {
    std::uniform_int_distribution<int> d(a, b);
    return d(rng());
}

int randomLength1(int minLen, int maxLen) {
    return randInt(minLen, maxLen);
}

static int gcd_int(int a, int b) {
    return std::gcd(a, b);
}

namespace EN {
Rational randomRational() {
    int n = randInt(-9, 9);
    int d;
    do { d = randInt(1, 9); } while (d == 0);

    int g = gcd_int(n, d);
    return { n / g, d / g };
}}

double EN:Rational::toDouble() const {
    if (den == 0) throw std::runtime_error("division by zero");
    return static_cast<double>(num) / static_cast<double>(den);
}

std::vector<EN::Rational> randomFractionList() {
    std::vector<EN::Rational> xs;
    int k = randomLength1();
    xs.reserve(k);
    for (int i = 0; i < k; ++i)
        xs.push_back(randomRational());
    return xs;
}
