#include "econ.h"

#include <numeric>
#include <algorithm>
#include <random>
#include <set>

using namespace std;

// -------------------- Primfaktorzerlegung --------------------
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

// -------------------- Produkt aller Elemente -----------------
int productList(const vector<int>& v) {
    return accumulate(v.begin(), v.end(), 1, multiplies<int>());
}

// -------------------- GGT von n Zahlen -----------------------
int gcdN(const vector<int>& nums) {
    return accumulate(nums.begin() + 1, nums.end(), nums[0],
                      [](int a, int b) { return gcd(a, b); });
}

// -------------------- Bruch kürzen ---------------------------
tuple<int,int> reduceFraction(int num, int den) {
    int g = gcd(num, den);
    return {num / g, den / g};
}

// -------------------- N Zahlen mit gemeinsamem Primfaktor ≥3 -
tuple<vector<int>, int> generateNUnique(int maxVal, int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(3, maxVal);

    while (true) {
        vector<int> numbers;
        set<int> uniq;

        while (numbers.size() < static_cast<size_t>(n)) {
            int x = dis(gen);
            if (uniq.insert(x).second)
                numbers.push_back(x);
        }

        vector<vector<int>> factors;
        for (int x : numbers)
            factors.push_back(primeFactors(x));

        set<int> commonSet(factors[0].begin(), factors[0].end());
        for (int i = 1; i < n; ++i) {
            set<int> tmp;
            set_intersection(commonSet.begin(), commonSet.end(),
                             factors[i].begin(), factors[i].end(),
                             inserter(tmp, tmp.begin()));
            commonSet = std::move(tmp);
        }

        int commonGCD = gcdN(numbers);

        if (!commonSet.empty() && commonGCD >= 3)
            return {numbers, commonGCD};
    }
}

// -------------------- Bruch anzeigen -------------------------
string showRational(int num, int den) {
    auto [rnum, rden] = reduceFraction(num, den);
    return to_string(rnum) + " / " + to_string(rden);
}
