#include <iostream>
#include <vector>
#include "econ.h"

using namespace std;

int main() {
    auto [nums, common] = generateNUnique(42);

    for (int n : nums)
        cout << n << "\n";

    int n1 = nums[0];
    int n2 = nums[1];
    int n3 = nums[2];

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
}
