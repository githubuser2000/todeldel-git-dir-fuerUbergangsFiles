#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <numeric>
#include <random>
#include <algorithm>

using namespace std;

// --- Primfaktorzerlegung ---
vector<int> prime_factors(int n) {
    vector<int> factors;
    for (int i = 2; i*i <= n; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

// --- Produkt von Vektorelementen ---
int product(const vector<int>& v) {
    return accumulate(v.begin(), v.end(), 1, multiplies<int>());
}

// --- Zufallszahlengenerator ---
mt19937 rng(random_device{}());
int randint(int a, int b) { // inklusiv
    uniform_int_distribution<int> dist(a, b);
    return dist(rng);
}

// --- Generiere drei unterschiedliche Zahlen ---
tuple<int,int,int,int> generate_three_unique(int max_val=42) {
    while (true) {
        vector<int> n1 = prime_factors(randint(3, max_val));
        vector<int> n2 = prime_factors(randint(3, max_val));
        vector<int> n3 = prime_factors(randint(3, max_val));

        // Prüfen, ob unterschiedlich
        if (n1 != n2 && n1 != n3 && n2 != n3) {
            int p1 = product(n1);
            int p2 = product(n2);
            int p3 = product(n3);

            int common = gcd(gcd(p1, p2), p3);
            if (common >= 3) {
                return {p1, p2, p3, common};
            }
        }
    }
}

// --- Bruch als pair<int,int> ---
struct Fraction {
    int num;
    int den;
    Fraction(int a, int b): num(a), den(b) {}
    double to_double() const { return static_cast<double>(num)/den; }
    Fraction operator*(const Fraction& other) const { return Fraction(num*other.num, den*other.den); }
    Fraction operator/(const Fraction& other) const { return Fraction(num*other.den, den*other.num); }
};

// --- Winkelberechnung θ = 2*atan(f) ---
pair<double,double> angle(const Fraction& f) {
    double x = f.to_double();
    double theta_rad = 2 * atan(x);
    double theta_deg = theta_rad * 180.0 / M_PI;
    return {theta_rad, theta_deg};
}

int main() {
    auto [n1, n2, n3, common] = generate_three_unique();

    cout << "zufällig generierte 3 unterschiedliche Zahlen mit unterschiedlichen Primfaktorzerlegungen: "
         << n1 << " " << n2 << " " << n3 << " verwandt " << common << endl;

    // Brüche
    Fraction q1(n1, n2), q2(n2, n3), q3(q1.num*q2.num, q1.den*q2.den), q4(q2.num*q1.num, q2.den*q1.den);

    vector<Fraction> S = {Fraction(n1,1), Fraction(n2,1), Fraction(n3,1), Fraction(common,1), q1, q2, q3, q4};

    vector<string> labels = {
        "Wert Geld Währung Nummer Zahlen Wert Währung (folgende sind Währungen von nicht Nummern Zahlen Werten) 💰 🔢 ⚖️",
        "Gutartigkeit Selbstlosigkeit Führungsschicht Regierung Herrschaft 😇 🏛️ 👑",
        "Ganzheit Kaputtheit Nicht-Armut Zentralität Unterschicht � 🏚️ 🛡️",
        "Primfaktor-Zerlegungs-Verwandschafts-Gemeinsamkeit dreier positiver zufälliger ganzer Natürlicher Zahlen Zahl � � 🔗",
        "Verhältnis Wert zu Führungsschicht, Gutartigkeit Produkt, Firma, Leistung als Winkel-Richtung � 🏹 📈",
        "Wert Verhältnis zu Unterschicht, Kaputtheit Armut Ganzheit Gesundheit zum Wert statt ins Verhältnis eine Skalierung � ⛓️ 🌡️",
        "Führungsschicht Regierer Parteien gegenüber Unterschicht Relation Verhältnis oder als Skarierung gemeint und zu verstehen, entweder oder 🏔️ ↕️ 👥",
        "Unterschicht Verhältnis zu Führungsschicht Regierung Herrscher Relation Verhältnis, oder als Skarierung gemeint und zu verstehen, entweder oder 🧗 ⛓️ ✊"
    };

    for (size_t i=0; i<labels.size() && i<S.size(); ++i) {
        cout << labels[i] << ": " << S[i].num;
        if (S[i].den != 1) cout << "/" << S[i].den;
        cout << endl;
    }

    // Winkel
    auto a1 = angle(q1);
    auto a2 = angle(q2);
    auto a3 = angle(q3);
    auto a4 = angle(q4);

    cout << "\n--- Winkel der vier rationalen Zahlen ---" << endl;
    cout << "q1 = " << q1.num << "/" << q1.den << "  →  θ = " << a1.first << " rad = " << a1.second << "°" << endl;
    cout << "q2 = " << q2.num << "/" << q2.den << "  →  θ = " << a2.first << " rad = " << a2.second << "°" << endl;
    cout << "q3 = " << q3.num << "/" << q3.den << "  →  θ = " << a3.first << " rad = " << a3.second << "°" << endl;
    cout << "q4 = " << q4.num << "/" << q4.den << "  →  θ = " << a4.first << " rad = " << a4.second << "°" << endl;

    cout << "\n--- Beziehung q ↔ 1/q (orthogonal = -180°) ---" << endl;
    cout << "θ(q1) - θ(q2) = " << a1.second - a2.second << "°" << endl;
    cout << "θ(q3) - θ(q4) = " << a3.second - a4.second << "°" << endl;

    // 8 Skalierungsfaktoren
    vector<Fraction> SCALE = {q1,q2,q3,q4, Fraction(q1.den,q1.num), Fraction(q2.den,q2.num), Fraction(q3.den,q3.num), Fraction(q4.den,q4.num)};
    cout << "\n--- Skalierungen auf n1, n2, n3 ---" << endl;
    for (auto& s : SCALE) {
        cout << s.num << "/" << s.den << " → "
             << s.to_double()*n1 << " "
             << s.to_double()*n2 << " "
             << s.to_double()*n3 << endl;
    }

    return 0;
}
