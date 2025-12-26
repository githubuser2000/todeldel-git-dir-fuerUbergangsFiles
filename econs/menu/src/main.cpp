#include <iostream>
#include "mode_text.h"
#include "mode_toggle.h"
#include "mode_ncurses.h"

int main() {
    std::cout <<
        "Modus waehlen:\n"
        "1 = Text-Eingabe\n"
        "2 = Toggle-TUI\n"
#ifdef USE_NCURSES
        "3 = ncurses-TUI\n"
#endif
        "Auswahl: ";

    int mode;
    std::cin >> mode;
    std::cin.ignore();

    if (mode == 1) mode_text();
    else if (mode == 2) mode_toggle();
#ifdef USE_NCURSES
    else if (mode == 3) mode_ncurses();
#endif
    else std::cout << "Ungueltig\n";
}
