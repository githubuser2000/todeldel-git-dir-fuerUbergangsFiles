// -*- coding: utf-8 -*-
#include "space.h"
#include <cmath>

std::array<double, 6> fractionTripletToSpace(
    const Rational& a,
    const Rational& b,
    const Rational& c
) {
    double x1 = a.toDouble();
    double x2 = b.toDouble();
    double x3 = c.toDouble();

    // simple illustrative mapping (kept as in your file)
    return {
        x1, x2, x3,
        std::sin(x1), std::cos(x2), std::tan(x3)
    };
}
