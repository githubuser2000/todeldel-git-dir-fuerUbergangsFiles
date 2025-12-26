#include "econ567emo2.h"
#include <iostream>
#include <numeric>
#include <random>
#include <cmath>
#include <algorithm>

using namespace std;

// --- Implementierungen ---
vector<int> prime_factors(int n) {
    vector<int> factors;
    for (int i = 2; i*i <= n; ++i)
        while (n % i == 0) { factors.push_back(i); n /= i; }
    if (n > 1) factors.push_back(n);
    return factors;
}

int product(const vector<int>& v) {
    return accumulate(v.begin(), v.end(), 1, multiplies<int>());
}

mt19937 rng(random_device{}());
int randint(int a, int b) { uniform_int_distribution<int> dist(a,b); return dist(rng); }

tuple<int,int,int,int> generate_three_unique(int max_val) {
    while (true) {
        vector<int> n1 = prime_factors(randint(3, max_val));
        vector<int> n2 = prime_factors(randint(3, max_val));
        vector<int> n3 = prime_factors(randint(3, max_val));
        if (n1 != n2 && n1 != n3 && n2 != n3) {
            int p1 = product(n1), p2 = product(n2), p3 = product(n3);
            int common = gcd(gcd(p1,p2),p3);
            if (common >= 3) return {p1,p2,p3,common};
        }
    }
}

Fraction::Fraction(int a, int b): num(a), den(b) {}
double Fraction::to_double() const { return static_cast<double>(num)/den; }
Fraction Fraction::operator*(const Fraction& other) const { return Fraction(num*other.num, den*other.den); }
Fraction Fraction::operator/(const Fraction& other) const { return Fraction(num*other.den, den*other.num); }

pair<double,double> angle(const Fraction& f) {
    double x = f.to_double();
    double rad = 2 * atan(x);
    return {rad, rad * 180.0 / M_PI};
}

// --- Alles ausführen ---
void run_econ567emo2() {
    auto [n1, n2, n3, common] = generate_three_unique();
    cout << "Zufällige Zahlen: " << n1 << " " << n2 << " " << n3 << " verwandt: " << common << endl;

    Fraction q1(n1,n2), q2(n2,n3), q3 = q1*q2, q4 = q2/q1;
    vector<Fraction> S = {Fraction(n1,1), Fraction(n2,1), Fraction(n3,1), Fraction(common,1), q1, q2, q3, q4};

    vector<string> labels = {
        "Wert Geld Währung Nummer Zahlen Wert Währung 💰 🔢 ⚖️",
        "Gutartigkeit Selbstlosigkeit Führungsschicht Regierung Herrschaft 😇 🏛️ 👑",
        "Ganzheit Kaputtheit Nicht-Armut Zentralität Unterschicht 🏚️ 🛡️",
        "Primfaktor-Zerlegungs-Gemeinsamkeit dreier positiver Zahlen 🔗",
        "Verhältnis Wert zu Führungsschicht, Gutartigkeit Produkt, Firma, Leistung 🏹 📈",
        "Wert Verhältnis zu Unterschicht, Kaputtheit Armut Ganzheit Gesundheit 🌡️",
        "Führungsschicht Regierer Parteien vs Unterschicht 🏔️ ↕️ 👥",
        "Unterschicht Verhältnis zu Führungsschicht, Regierung, Herrscher 🧗 ⛓️ ✊"
    };

    for (size_t i=0; i<labels.size() && i<S.size(); ++i) {
        cout << labels[i] << ": " << S[i].num;
        if (S[i].den != 1) cout << "/" << S[i].den;
        cout << endl;
    }

    auto a1 = angle(q1), a2 = angle(q2), a3 = angle(q3), a4 = angle(q4);
    cout << "\n--- Winkel ---\n";
    cout << "q1: " << a1.second << "°, q2: " << a2.second << "°, q3: " << a3.second << "°, q4: " << a4.second << "°\n";

    vector<Fraction> SCALE = {q1,q2,q3,q4, Fraction(q1.den,q1.num), Fraction(q2.den,q2.num), Fraction(q3.den,q3.num), Fraction(q4.den,q4.num)};
    cout << "\n--- Skalierungen auf n1, n2, n3 ---\n";
    for (auto& s: SCALE)
        cout << s.num << "/" << s.den << " → " << s.to_double()*n1 << " " << s.to_double()*n2 << " " << s.to_double()*n3 << endl;
}
