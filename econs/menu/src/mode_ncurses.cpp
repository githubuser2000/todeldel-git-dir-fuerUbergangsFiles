#include "mode_ncurses.h"
#include "bitmask.h"
#include <notMain567a.h>
#include <notMain567b.h>
#include "check.h"
#include <notMainDe.h>
//#include <notMainEn.h>

#ifdef USE_NCURSES
#include <ncurses.h>
#include <set>
#include <iostream>

void mode_ncurses() {
    initscr();
    noecho();
    keypad(stdscr, true);
    curs_set(0);

    std::set<int> selected;
    int cursor = 0; // Cursor von 0 bis 11 (für 12 Elemente)

    while (true) {
        clear();
        for (int i = 1; i <= 12; ++i) { // 1 bis 12
            if (i - 1 == cursor) attron(A_REVERSE);
            printw("[%c] %d\n", selected.count(i) ? 'x' : ' ', i);
            if (i - 1 == cursor) attroff(A_REVERSE);
        }
        refresh();

        int ch = getch();
        if (ch == KEY_UP && cursor > 0)
            cursor--;
        else if (ch == KEY_DOWN && cursor < 11) // 0 bis 11
            cursor++;
        else if (ch == ' ') {
            int v = cursor + 1; // Cursor 0–11 → Werte 1–12
            if (selected.count(v))
                selected.erase(v);
            else
                selected.insert(v);
        }
        else if (ch == 10) // Enter
            break;
        else if (ch == 27) { // Escape
            selected.clear();
            break;
        }
    }

    endwin();

    std::cout << "Auswahl: ";
    for (int n : selected) std::cout << n << " ";
    std::cout << "\nBitmaske: " << toBitmask(selected) << "\n";

    check(selected);
}
#endif
