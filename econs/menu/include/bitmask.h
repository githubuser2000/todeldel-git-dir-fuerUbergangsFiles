#ifndef BITMASK_H
#define BITMASK_H

#include <set>

int toBitmask(const std::set<int>& s);
std::set<int> fromBitmask(int mask);

#endif
