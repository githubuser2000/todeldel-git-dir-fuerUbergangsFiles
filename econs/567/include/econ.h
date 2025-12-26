#ifndef ECON_H
#define ECON_H

#include <vector>
#include <tuple>
#include <string>

#define THREE 3

// Primfaktorzerlegung
std::vector<int> primeFactors(int n);

// Produkt aller Elemente
int productList(const std::vector<int>& v);

// GGT von n Zahlen
int gcdN(const std::vector<int>& nums);

// Bruch kürzen
std::tuple<int,int> reduceFraction(int num, int den);

// N Zahlen mit gemeinsamem Primfaktor ≥3
std::tuple<std::vector<int>, int> generateNUnique(int maxVal, int n = THREE);

// Bruch anzeigen
std::string showRational(int num, int den);

#endif
