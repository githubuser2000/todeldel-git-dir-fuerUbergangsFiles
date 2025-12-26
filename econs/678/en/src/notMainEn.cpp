#include "encoding_utf8.h"
#include "rational.h"
#include "space.h"
#include <iostream>
#include <locale>
#include <notMainEn.h>


void banner(const char* title) {
    std::cout << BOX_LINE << "\n" << title << "\n" << BOX_LINE << "\n";
}
std::cout << reinterpret_cast<const char*>(BOX_LINE) << "\n";
void endtext_geometry() {
    std::cout << u8"◈ Geometrie\n"
                 u8"   • Richtungswinkel\n"
                 u8"   • Steigung in Matrizen\n\n";
}

void endtext_diplomacy() {
    std::cout << u8"◈ Diplomatie\n"
                 u8"   • Macht-, Einfluss- und Abhängigkeitsverhältnisse\n\n";
}

void out() {
    auto xs = randomFractionList();
    auto spaces = fractionsToSpaces(xs);

    banner(TITLE_RATIONAL);
    std::cout << ICON_REL << u8" Brüche  →  " << ICON_INT << u8" "
              << TITLE_SPACE << "\n\n";

    for (const auto& s : spaces) {
        std::cout << " (";
        for (size_t i = 0; i < s.size(); ++i) {
            std::cout << s[i];
            if (i + 1 < s.size()) std::cout << ", ";
        }
        std::cout << ")\n";
    }
    std::cout << "\n";
}

int start678en() {
    std::locale::global(std::locale("C.UTF-8"));

    out();
    endtext_geometry();
    endtext_diplomacy();
    out();
}
