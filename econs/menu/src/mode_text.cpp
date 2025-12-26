#include "mode_text.h"
#include "bitmask.h"
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <notMain567a.h>
#include <notMain567b.h>
#include "check.h"
#include <notMainDe.h>
//#include <notMainEn.h>

// Hier die modularisierten Funktionen der *6* Programme einbinden


void mode_text() {
    std::set<int> allowed = {1,2,3,4,5,6,7,8,9,10,11,12};
    std::set<int> selected;

    std::cout << "Eingabe (z.B. 2 5 6 7 8): ";
    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    int n;
    while (iss >> n)
        if (allowed.count(n)) selected.insert(n);

    std::cout << "Auswahl: ";
    for (int x : selected) std::cout << x << " ";

    std::cout << "\nBitmaske: " << toBitmask(selected) << "\n";

    check(selected);
}
