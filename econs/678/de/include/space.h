// -*- coding: utf-8 -*-
#pragma once

#include <array>
#include "rational.hpp"

// maps 3 rational values into a 6-tuple “space representation”
std::array<double, 6> fractionTripletToSpace(
    const Rational& a,
    const Rational& b,
    const Rational& c
);
