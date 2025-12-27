#include "crc_struct.h"
#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <cstdint>
// main_guard.h
#pragma once

#ifndef MAIN_ALREADY_DEFINED
#define MAIN_ALREADY_DEFINED
#define ENABLE_THIS_MAIN
#endif
// CRC32 Tabelle initialisieren
static uint32_t crc32_table[256];

static void init_crc32_table() {
    static bool initialized = false;
    if(initialized) return;

    for(uint32_t i=0; i<256; i++){
        uint32_t crc = i;
        for(uint32_t j=0;j<8;j++)
            crc = (crc >> 1) ^ (0xEDB88320 & (-(int)(crc & 1)));
        crc32_table[i] = crc;
    }
    initialized = true;
}

static void updateCRC(uint32_t &crc, const std::string &s){
    for(char c : s)
        crc = (crc >> 8) ^ crc32_table[(crc ^ c) & 0xFF];
}

static void updateCRC(uint32_t &crc, int x){
    for(int i=0;i<4;i++)
        crc = (crc >> 8) ^ crc32_table[(crc ^ ((x >> (i*8)) & 0xFF)) & 0xFF];
}

// Rekursive CRC-Berechnung
uint32_t computeCRC(const std::shared_ptr<CrcData> &data){
    init_crc32_table();
    uint32_t crc = 0xFFFFFFFF;

    std::function<void(const std::shared_ptr<CrcData>&)> recurse;
    recurse = [&](const std::shared_ptr<CrcData>& d){
        updateCRC(crc,d->utf8string);
        updateCRC(crc,d->signaturasciistring);
        updateCRC(crc,d->asciiueberschrift);
        updateCRC(crc,d->asciisignatur);
        for(const auto &s : d->utf8emoticonhashtagliste)
            updateCRC(crc,s);

        updateCRC(crc,d->intanzahlbaumbloeckevorher);
        updateCRC(crc,d->intanzahlbaumbloeckenachher);
        updateCRC(crc,d->intanzahlbaumbloeckehier);
        updateCRC(crc,d->crcbaumbloeckehier);

        for(const auto &prev : d->vorherigeBloecke)
            recurse(prev);
    };

    recurse(data);
    return crc ^ 0xFFFFFFFF;
}

// CRC Check mit optionaler Manipulation
void checkCRC(const std::shared_ptr<CrcData> &data, int delta=0){
    uint32_t referenceCRC = computeCRC(data); // Referenz berechnen
    std::cout << "Referenz CRC: " << referenceCRC << "\n";

    // Test-CRC ggf. manipulieren
    uint32_t testCRC = referenceCRC + delta;
    std::cout << "Berechneter CRC: " << testCRC << "\n";

    if(testCRC == referenceCRC)
        std::cout << "Status: genau richtig!\n";
    else if(testCRC < referenceCRC)
        std::cout << "Status: daneben (zu klein)\n";
    else
        std::cout << "Status: danach (zu groß)\n";
}

int main() {
    auto block1 = std::make_shared<CrcData>();
    block1->utf8string = "Block1";
    block1->intanzahlbaumbloeckehier = 1;

    auto block2 = std::make_shared<CrcData>();
    block2->utf8string = "Block2";
    block2->intanzahlbaumbloeckehier = 2;
    block2->vorherigeBloecke.push_back(block1);

    auto block3 = std::make_shared<CrcData>();
    block3->utf8string = "Block3";
    block3->intanzahlbaumbloeckehier = 3;
    block3->vorherigeBloecke.push_back(block2);

    std::cout << "\n--- Test 1: exakter CRC ---\n";
    checkCRC(block3, 0); // exakt

    std::cout << "\n--- Test 2: CRC kleiner (daneben) ---\n";
    checkCRC(block3, -1); // daneben

    std::cout << "\n--- Test 3: CRC größer (danach) ---\n";
    checkCRC(block3, +1); // danach

    return 0;
}
