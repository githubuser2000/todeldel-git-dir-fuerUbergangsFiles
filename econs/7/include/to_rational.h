#ifndef TO_RATIONAL_H
#define TO_RATIONAL_H

#include <string>

enum class AngleInputType {
    Degrees,
    Radians,
    PiUnits,
    CirclePercent
};

double convert_to_rational(double value, AngleInputType type);
std::string describe_rational(double q);

#endif // TO_RATIONAL_H
