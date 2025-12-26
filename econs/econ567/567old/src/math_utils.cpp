#include "math_utils.h"
#include <numeric>
#include <algorithm>
#include <random>

using namespace std;

vector<int> primeFactors(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

int productList(const vector<int>& v) {
    return accumulate(v.begin(), v.end(), 1, multiplies<int>());
}

int gcd3(int a, int b, int c) {
    return gcd(gcd(a, b), c);
}

tuple<int,int> reduceFraction(int num, int den) {
    int g = gcd(num, den);
    return {num/g, den/g};
}

tuple<int,int,int,int> generateThreeUnique(int maxVal) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(3, maxVal);

    while (true) {
        int n1 = dis(gen);
        int n2 = dis(gen);
        int n3 = dis(gen);

        if (n1 == n2 || n1 == n3 || n2 == n3) continue;

        auto f1 = primeFactors(n1);
        auto f2 = primeFactors(n2);
        auto f3 = primeFactors(n3);

        int p1 = productList(f1);
        int p2 = productList(f2);
        int p3 = productList(f3);

        int common = gcd3(p1, p2, p3);

        vector<int> intersect;
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        sort(f3.begin(), f3.end());
        set_intersection(f1.begin(), f1.end(), f2.begin(), f2.end(), back_inserter(intersect));
        vector<int> finalIntersect;
        set_intersection(intersect.begin(), intersect.end(), f3.begin(), f3.end(), back_inserter(finalIntersect));

        if (!finalIntersect.empty() && common >= 3) {
            return {p1, p2, p3, common};
        }
    }
}

string showRational(int num, int den) {
    auto [rnum, rden] = reduceFraction(num, den);
    return to_string(rnum) + " / " + to_string(rden);
}
