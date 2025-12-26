#ifndef FROM_RATIONAL_H
#define FROM_RATIONAL_H

#include <string>
#include <limits>

struct AngleResult {
    double rational;       // Dezimalwert
    double degrees;        // Grad
    double radians;        // Radiant
    double pi_units;       // Vielfaches von pi
    double circle_percent; // Prozent des Kreises
    double n_value;        // Cot-Mapping Wert (n-System)
};

double parse_fraction(const std::string& s);
double cot(double rad);

AngleResult convert_from_rational(double q);
std::string format_angle_result(const AngleResult& r);

#endif // FROM_RATIONAL_H
