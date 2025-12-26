#pragma once
#include <vector>

namespace EN {
    struct Rational;
}
struct EN::Rational {
    int num;
    int den;
    double toDouble() const;
};

int randInt(int a, int b);
int randomLength1 (int minLen = 4, int maxLen = 12);
EN::Rational randomRational();
std::vector<EN::Rational> randomFractionList();
