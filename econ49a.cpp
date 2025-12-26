#include <iostream>
#include <sstream>
#include <set>

int main() {
    std::set<int> erlaubt = {3, 4, 5, 6, 7, 8, 9};
    std::set<int> auswahl;

    std::cout << "Waehle Zahlen aus {3 4 5 6 7 8 9}\n";
    std::cout << "Eingabe (mit Leerzeichen getrennt): ";

    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    int n;
    while (iss >> n) {
        if (erlaubt.count(n)) {
            auswahl.insert(n);
        }
    }

    std::cout << "\nAusgewaehlt wurden: ";
    for (int x : auswahl) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
