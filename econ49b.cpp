// main.cpp
// Build:
//   Normal TUI:      g++ main.cpp -o tui
//   Ncurses TUI:     g++ main.cpp -DUSE_NCURSES -lncurses -o tui

#include <iostream>
#include <set>
#include <sstream>
#include <string>

#ifdef USE_NCURSES
#include <ncurses.h>
#endif

// ---------- Bitmask ----------
int toBitmask(const std::set<int>& s) {
    int mask = 0;
    for (int n : s) mask |= 1 << (n - 3);
    return mask;
}

std::set<int> fromBitmask(int mask) {
    std::set<int> s;
    for (int i = 0; i < 7; ++i)
        if (mask & (1 << i)) s.insert(i + 3);
    return s;
}

// ---------- Mode 1: Text Input ----------
void mode_text() {
    std::set<int> allowed = {3,4,5,6,7,8,9};
    std::set<int> selected;

    std::cout << "Eingabe (z.B. 3 5 7): ";
    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    int n;
    while (iss >> n)
        if (allowed.count(n)) selected.insert(n);

    std::cout << "Auswahl: ";
    for (int x : selected) std::cout << x << " ";
    std::cout << "\nBitmaske: " << toBitmask(selected) << "\n";
}

// ---------- Mode 2: Simple Toggle ----------
void mode_toggle() {
    std::set<int> selected;

    while (true) {
        system("clear"); // Windows: cls
        for (int i = 3; i <= 9; ++i)
            std::cout << "[" << (selected.count(i) ? 'x' : ' ') << "] " << i << "\n";

        std::cout << "\n3-9 toggle | q = fertig: ";
        char c;
        std::cin >> c;

        if (c == 'q') break;
        if (c >= '3' && c <= '9') {
            int v = c - '0';
	    if (selected.count(v)) {
    		selected.erase(v);
	    } else {
    		selected.insert(v);
	    }
        }
    }

    std::cout << "\nAuswahl: ";
    for (int n : selected) std::cout << n << " ";
    std::cout << "\nBitmaske: " << toBitmask(selected) << "\n";
}

#ifdef USE_NCURSES
// ---------- Mode 3: ncurses ----------
void mode_ncurses() {
    initscr();
    noecho();
    keypad(stdscr, true);
    curs_set(0);

    std::set<int> selected;
    int cursor = 0;

    while (true) {
        clear();
        for (int i = 0; i < 7; ++i) {
            int v = i + 3;
            if (i == cursor) attron(A_REVERSE);
            printw("[%c] %d\n", selected.count(v) ? 'x' : ' ', v);
            if (i == cursor) attroff(A_REVERSE);
        }
        refresh();

        int ch = getch();
        if (ch == KEY_UP && cursor > 0) cursor--;
        else if (ch == KEY_DOWN && cursor < 6) cursor++;
        else if (ch == ' ') {
            int v = cursor + 3;
            selected.count(v) ? selected.erase(v) : selected.insert(v);
        }
        else if (ch == 10) break;   // Enter
        else if (ch == 27) { selected.clear(); break; } // ESC
    }

    endwin();

    std::cout << "Auswahl: ";
    for (int n : selected) std::cout << n << " ";
    std::cout << "\nBitmaske: " << toBitmask(selected) << "\n";
}
#endif

// ---------- Main ----------
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
