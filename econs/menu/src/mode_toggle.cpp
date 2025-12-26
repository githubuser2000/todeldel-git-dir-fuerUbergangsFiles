#include "mode_toggle.h"
#include "bitmask.h"
#include "check.h"

#include <iostream>
#include <set>
#include <notMainDe.h>
//#include <notMainEn.h>

void mode_toggle()
{
    std::set<int> selected;

    while (true) {
        system("clear");

        for (int i = 1; i <= 12; ++i)
            std::cout << "[" << (selected.count(i) ? 'x' : ' ') << "] " << i << "\n";

        std::cout << "\n1-9 toggle | q = fertig: ";
        char c;
        std::cin >> c;

        if (c == 'q') break;
        if (c >= '0' && c <= '9') {
            int v = c - '0';
            if (selected.count(v)) selected.erase(v);
            else selected.insert(v);
        }
    }

    std::cout << "\nAuswahl: ";
    for (int n : selected) std::cout << n << " ";
    std::cout << "\n";

    // 👉 Auswertung in separater Datei
    check(selected);
}
