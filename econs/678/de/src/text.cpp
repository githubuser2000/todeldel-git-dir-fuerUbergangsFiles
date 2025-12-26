// -*- coding: utf-8 -*-
#include <text.h>
#include <iostream>
#include <rational.hpp>


// randomLength.cpp
#include <random>

unsigned long randomLength(unsigned long a, unsigned long b) {
    static std::mt19937 rng{std::random_device{}()};
    std::uniform_int_distribution<unsigned long> dist(a, b);
    return dist(rng);
}


void out() {
    auto n = randomLength(3, 12);
    std::vector<Rational> v = randomTriplet(n);

    for (std::size_t i = 0; i + 2 < v.size(); i += 3) {
        auto s = fractionTripletToSpace(v[i], v[i+1], v[i+2]);
        std::cout
            << "⇒ (" << s[0] << "," << s[1] << "," << s[2]
            << ") → (" << s[3] << "," << s[4] << "," << s[5]
            << ")\n";
    }
}

// --- UTF-8 text blocks preserved from your program ---

void endtext1() {

    std::cout << "\n";
    std::cout << "══════════════════════════════════════════════\n";
    std::cout << "🔢  GANZZAHL – Zustand im dimensionalen Raum\n";
    std::cout << "══════════════════════════════════════════════\n";

    std::cout << "🧠 Bedeutung:\n";
    std::cout << "   ① 💰 Marktwirtschaft\n";
    std::cout << "      → absoluter Trieb- oder Wertzustand\n\n";

    std::cout << "   ② 💱 Währung\n";
    std::cout << "      → isolierte Währung\n";
    std::cout << "      → kein Umtauschverhältnis\n\n";

    std::cout << "   ③ 🏗️ Kommunismus-Zustände\n";
    std::cout << "      • Armut\n";
    std::cout << "      • Reparatur-Zustand\n";
    std::cout << "      • Gesundheits-/Krankheits-Zustand\n";
    std::cout << "      • Schwäche / Zentralität / Impulsivität\n\n";

    std::cout << "   ④ 📐 Geometrie\n";
    std::cout << "      → Volumen- oder Flächeneinheit\n\n";

    std::cout << "   ⑤ 🧭 Hierarchie\n";
    std::cout << "      → Rangordnung (oben / unten)\n";
    std::cout << "══════════════════════════════════════════════\n";
    std::cout <<
"══════════════════════════════════════════════\n"
"🔢  GANZE ZAHL – Einheit im Raum\n"
"══════════════════════════════════════════════\n"
"① 🧱 Struktur  → Baustein / Element\n"
"② 🧮 Algebra   → Zähl- oder Ordnungsobjekt\n"
"③ 🏗️ Architektur → Raster / Modul / Achse\n"
"④ 📐 Geometrie → Volumen- oder Flächeneinheit\n"
"⑤ 🧭 Hierarchie → Rangordnung (oben / unten)\n"
"══════════════════════════════════════════════\n";
}

void endtext2() {

    std::cout << "\n";
    std::cout << "══════════════════════════════════════════════\n";
    std::cout << "🔁  RATIONALE ZAHL – Relation im Raum\n";
    std::cout << "══════════════════════════════════════════════\n";

    std::cout << "🧠 Bedeutung:\n";
    std::cout << "   ① 💱 Währungen\n";
    std::cout << "      → Wechselkurs / Verhältnis\n\n";

    std::cout << "   ② 🧭 Geometrie (2D)\n";
    std::cout << "      → Richtungswinkel\n";
    std::cout << "      → Steigung in einer Matrix\n\n";

    std::cout << "   ③ 🤝 Diplomatie\n";
    std::cout << "      → Macht-, Einfluss- oder Abhängigkeitsverhältnis\n\n";

    std::cout << "   ④ 🧑‍🤝‍🧑 Soziales System\n";
    std::cout << "      → Wer mit wem\n";
    std::cout << "      → Beziehungsstruktur\n";
    std::cout << "══════════════════════════════════════════════\n";
    std::cout << "Handelbar sind Tickets, Immobilien,  Mobilien Grund und Boden, Tiere,  Menschen,  Raumschiffe,  Fähren,  Legierungen,  Häuser durch Quader statt Währungsgeld aus Zahlenwerten als Währung für NATO Warschauer Pakt Organisationen.\n";

    std::cout <<
"\n══════════════════════════════════════════════\n"
"🔁  RATIONALE ZAHL – Relation im Raum\n"
"══════════════════════════════════════════════\n"
"🧠 Bedeutung:\n"
"① 💱 Währungen  → Wechselkurs / Verhältnis\n"
"② 🧭 Geometrie → Richtungswinkel / Steigung\n"
"③ 🤝 Diplomatie → Macht- oder Abhängigkeitsverhältnis\n";
}
