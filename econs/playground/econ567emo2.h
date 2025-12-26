#ifndef ECON567EMO2_H
#define ECON567EMO2_H

#include <vector>
#include <tuple>
#include <utility>

// --- Primfaktorzerlegung ---
std::vector<int> prime_factors(int n);

// --- Produkt von Vektorelementen ---
int product(const std::vector<int>& v);

// --- Zufallszahlengenerator ---
int randint(int a, int b); // inklusiv

// --- Generiere drei unterschiedliche Zahlen ---
std::tuple<int,int,int,int> generate_three_unique(int max_val=42);

// --- Bruchstruktur ---
struct Fraction {
    int num;
    int den;
    Fraction(int a=0, int b=1);
    double to_double() const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;
};

// --- Winkelberechnung θ = 2*atan(f) ---
std::pair<double,double> angle(const Fraction& f);

#endif // ECON567EMO2_H
