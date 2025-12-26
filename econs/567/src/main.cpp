#include <iostream>
#include <vector>
#include <string>
// Vorher
//#include "../567/include/math_utils.h"
// Nachher
#include "math_utils.h"
using namespace std;


int main() {
    auto [n1, n2, n3, common] = generateThreeUnique(42);

    int q1_num = n1, q1_den = n2;
    int q2_num = n2, q2_den = n3;

    int q3_num = q1_num * q2_den;
    int q3_den = q1_den * q2_num;

    int q4_num = q2_num * q1_den;
    int q4_den = q2_den * q1_num;

    vector<string> labels = {
        "Wert Geld Währung Nummer Zahlen Wert Währung (folgende sind Währungen von nicht Nummern Zahlen Werten)",
        "Gutartigkeit Selbstlosigkeit Führungschicht Regierung Herrschaft",
        "Ganzheit Kaputtheit Nicht-Armut Zentralität Unterschicht",
        "Primfaktor-Zerlegungs-Verwandschafts-Gemeinsamkeit dreier positiver zufälliger ganzer Natürlicher Zahlen Zahl",
        "Verhältnis Wert zu Führungsschicht, Gutartigkeit Produkt, Firma, Leistung als Winkel-Richtung",
        "Wert Verhältnis zu Unterschicht, Kaputtheit Armut Ganzheit Gesundheit zum Wert statt ins Verhältnis eine Skalierung",
        "Führungsschicht Regierer Parteien gegenüber Unterschicht Relation Verhältnis oder als Skarierung gemeint und zu verstehen, entweder oder",
        "Unterschicht Verhältnis zu Führungsschicht Regierung Herrscher Relation Verhältnis, oder als Skarierung gemeint und zu verstehen, entweder oder"
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

    for (size_t i = 0; i < labels.size(); ++i) {
        cout << labels[i] << ": " << values[i] << endl;
    }

    return 0;
}
