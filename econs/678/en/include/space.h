#pragma once
#include "rational.h"
#include <array>
#include <vector>

using Space = std::array<double, 6>;

std::pair<double,double> convertOne(const EN::Rational& r);
Space fractionTripletToSpace(const EN::Rational& a,
                             const EN::Rational& b,
                             const EN::Rational& c);
std::vector<Space> fractionsToSpaces(const std::vector<EN::Rational>& v);
