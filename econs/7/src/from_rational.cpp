#include "from_rational.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include <iostream>

static constexpr double PI = 3.14159265358979323846;

// Brüche p/q parsen
double parse_fraction(const std::string& s) {
    size_t pos = s.find('/');
    if (pos != std::string::npos) {
        double numerator = std::stod(s.substr(0,pos));
        double denominator = std::stod(s.substr(pos+1));
        return numerator / denominator;
    } else {
        return std::stod(s);
    }
}

// Cotangens Funktion mit Grenzwertbehandlung
double cot(double rad) {
    double s = std::sin(rad);
    if (std::abs(s) < 1e-12) return std::copysign(std::numeric_limits<double>::infinity(), std::cos(rad));
    return std::cos(rad)/s;
}

// Umrechnung rational -> Winkel + n-System
AngleResult convert_from_rational(double q) {
    AngleResult r{};
    r.rational = q;
    r.degrees = q * 360.0;
    r.radians = q * 2.0 * PI;
    r.pi_units = r.radians / PI;
    r.circle_percent = q * 100.0;
    r.n_value = cot(r.radians);
    return r;
}

// Formatierte Ausgabe
std::string format_angle_result(const AngleResult& r) {
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(6);
    ss << "rational = " << r.rational << "\n";
    ss << "degrees = " << r.degrees << "°\n";
    ss << "radians = " << r.radians << " rad\n";
    ss << "pi_units = " << r.pi_units << " * pi\n";
    ss << "circle_percent = " << r.circle_percent << " %\n";
    ss << "n_value (cot mapping) = " << r.n_value << "\n";
    return ss.str();
}

// CLI Entry
#ifdef BUILD_MAIN
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: from_rational <number_or_fraction>\n";
        return 1;
    }

    double q = parse_fraction(argv[1]);
    auto r = convert_from_rational(q);
    std::cout << format_angle_result(r);
    return 0;
}
#endif
