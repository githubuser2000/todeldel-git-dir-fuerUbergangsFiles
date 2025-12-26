#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <tuple>
#include <string>
#include <set>
#define THREE 3
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
tuple<vector<int>, int> generateNUnique(int maxVal, int n = THREE) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(3, maxVal);

    while (true) {
        vector<int> numbers;
        set<int> uniq;

        // n verschiedene Zahlen erzeugen
        while (numbers.size() < n) {
            int x = dis(gen);
            if (uniq.insert(x).second)
                numbers.push_back(x);
        }

        // Primfaktorzerlegungen
        vector<vector<int>> factors;
        for (int x : numbers)
            factors.push_back(primeFactors(x));

        // Gemeinsame Primfaktoren
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

// -------------------- main -----------------------------------
int main() {
    auto [nums, common] = generateNUnique(42); // n = 3 (Default)

    int n1 = nums[0];
    int n2 = nums[1];
    int n3 = nums[2];
    for (int n : nums) {
      std::cout << n << "\n";
    }

    // Rationalzahlen
    int q1_num = n1, q1_den = n2;
    int q2_num = n2, q2_den = n3;

    int q3_num = q1_num * q2_den;
    int q3_den = q1_den * q2_num;

    int q4_num = q2_num * q1_den;
    int q4_den = q2_den * q1_num;

    vector<string> labels = {
        "Wert Geld Währung Nummer Zahlen Wert Währung",
        "Gutartigkeit Selbstlosigkeit Führungsschicht",
        "Ganzheit Kaputtheit Nicht-Armut Unterschicht",
        "Gemeinsamer Primfaktor (>=3)",
        "q1 = n1 / n2",
        "q2 = n2 / n3",
        "q3 = q1 / q2",
        "q4 = q2 / q1"
    };

    vector<string> values = {
        to_string(n1),
        to_string(n2),
        to_string(n3),
        to_string(common),
        showRational(q1_num, q1_den),
        showRational(q2_num, q2_den),
        showRational(q3_num, q3_den),
        showRational(q4_num, q4_den)
    };

    for (size_t i = 0; i < labels.size(); ++i)
        cout << labels[i] << ": " << values[i] << endl;

    return 0;
}
