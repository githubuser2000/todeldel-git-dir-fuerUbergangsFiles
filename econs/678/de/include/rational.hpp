// -*- coding: utf-8 -*-
#pragma once

#include <vector>
#include <array>
#include <random>

struct Rational {
    int num;
    int den;

    double toDouble() const {
        return static_cast<double>(num) / static_cast<double>(den);
    }
};

Rational randomRational(int min = 1, int max = 9);
std::size_t randomLength(std::size_t min = 6, std::size_t max = 12);
std::vector<Rational> randomTriplet(std::size_t n);
Rational randomRational(int min, int max);
