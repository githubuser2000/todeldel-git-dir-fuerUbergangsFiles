#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <vector>
#include <tuple>
#include <string>

std::vector<int> primeFactors(int n);
int productList(const std::vector<int>& v);
int gcd3(int a, int b, int c);
std::tuple<int,int> reduceFraction(int num, int den);
std::tuple<int,int,int,int> generateThreeUnique(int maxVal);
std::string showRational(int num, int den);

#endif // MATH_UTILS_H
