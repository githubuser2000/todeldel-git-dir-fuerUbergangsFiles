#include "bitmask.h"

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
