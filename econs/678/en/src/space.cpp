#include "space.h"
#include <cmath>

std::pair<double,double> convertOne(const EN::Rational& r) {
    double x = r.toDouble();
    return { x, 1.0 / (1.0 + std::abs(x)) };
}

Space fractionTripletToSpace(const EN::Rational& a,
                             const EN::Rational& b,
                             const EN::Rational& c)
{
    auto [a1,a2] = convertOne(a);
    auto [b1,b2] = convertOne(b);
    auto [c1,c2] = convertOne(c);

    return { a1,a2, b1,b2, c1,c2 };
}

std::vector<Space> fractionsToSpaces(const std::vector<Rational>& v) {
    std::vector<Space> out;
    for (size_t i = 0; i + 2 < v.size(); i += 3)
        out.push_back(fractionTripletToSpace(v[i], v[i+1], v[i+2]));
    return out;
}
