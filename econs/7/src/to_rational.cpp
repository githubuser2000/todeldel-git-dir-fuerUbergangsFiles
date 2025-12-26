#include "to_rational.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include <iostream>

static constexpr double PI = 3.14159265358979323846;

double convert_to_rational(double value, AngleInputType type) {
    switch (type) {
        case AngleInputType::Degrees:
            return value / 360.0;
        case AngleInputType::Radians:
            return value / (2.0 * PI);
        case AngleInputType::PiUnits:
            return value / 2.0; // value = k*pi
        case AngleInputType::CirclePercent:
            return value / 100.0;
    }
    return NAN;
}

std::string describe_rational(double q) {
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(6);
    ss << "rational(turns) = " << q << "\n";
    ss << "degrees = " << q*360.0 << "°\n";
    ss << "radians = " << q*2.0*PI << " rad\n";
    ss << "pi_units = " << q*2.0 << " * pi\n";
    ss << "circle_percent = " << q*100.0 << " %\n";
    return ss.str();
}

#ifdef BUILD_MAIN
int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: to_rational <type> <value>\n";
        std::cerr << "Types: deg | rad | pi | pct\n";
        return 1;
    }

    std::string t = argv[1];
    double v = std::stod(argv[2]);

    AngleInputType type;
    if (t=="deg") type = AngleInputType::Degrees;
    else if (t=="rad") type = AngleInputType::Radians;
    else if (t=="pi")  type = AngleInputType::PiUnits;
    else if (t=="pct") type = AngleInputType::CirclePercent;
    else {
        std::cerr << "Unknown type. Use: deg | rad | pi | pct\n";
        return 2;
    }

    double q = convert_to_rational(v,type);
    std::cout << describe_rational(q);
    return 0;
}
#endif
