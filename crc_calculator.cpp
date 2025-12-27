#include "crc_calculator.h"
#include <iostream>

// CRC32-Tabelle
static uint32_t crc32_table[256];

static void init_crc32_table() {
    static bool initialized = false;
    if (initialized) return;

    for (uint32_t i = 0; i < 256; i++) {
        uint32_t crc = i;
        for (uint32_t j = 0; j < 8; j++)
            crc = (crc >> 1) ^ (0xEDB88320 & (-(int)(crc & 1)));
        crc32_table[i] = crc;
    }
    initialized = true;
}

namespace CRC {

static void updateCRC(uint32_t &crc, const std::string &s) {
    for(char c : s)
        crc = (crc >> 8) ^ crc32_table[(crc ^ c) & 0xFF];
}

static void updateCRC(uint32_t &crc, int x) {
    for(int i=0; i<4; ++i)
        crc = (crc >> 8) ^ crc32_table[(crc ^ ((x >> (i*8)) & 0xFF)) & 0xFF];
}

// Rekursive CRC-Berechnung
uint32_t computeCRC(const std::shared_ptr<CrcData> &data) {
    init_crc32_table();
    uint32_t crc = 0xFFFFFFFF;

    std::function<void(const std::shared_ptr<CrcData>&)> recurse;
    recurse = [&](const std::shared_ptr<CrcData>& d){
        updateCRC(crc, d->utf8string);
        updateCRC(crc, d->signaturasciistring);
        updateCRC(crc, d->asciiueberschrift);
        updateCRC(crc, d->asciisignatur);

        for(const auto &s : d->utf8emoticonhashtagliste)
            updateCRC(crc, s);

        updateCRC(crc, d->intanzahlbaumbloeckevorher);
        updateCRC(crc, d->intanzahlbaumbloeckenachher);
        updateCRC(crc, d->intanzahlbaumbloeckehier);
        updateCRC(crc, d->crcbaumbloeckehier);

        for(const auto &prev : d->vorherigeBloecke)
            recurse(prev);
    };

    recurse(data);

    return crc ^ 0xFFFFFFFF;
}

void checkCRC(const std::shared_ptr<CrcData> &data, uint32_t referenceCRC) {
    uint32_t crc = computeCRC(data);
    std::cout << "Berechneter CRC: " << crc << "\n";
    std::cout << "Referenz CRC: " << referenceCRC << "\n";

    if(crc == referenceCRC)
        std::cout << "Status: genau richtig!\n";
    else if(crc < referenceCRC)
        std::cout << "Status: daneben (zu klein)\n";
    else
        std::cout << "Status: danach (zu groß)\n";
}

} // namespace CRC
