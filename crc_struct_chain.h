#ifndef CRC_STRUCT_H
#define CRC_STRUCT_H

#include <string>
#include <vector>
#include <iostream>
#include <memory> // für shared_ptr

struct CrcData {
    // CRC-Werte
    unsigned int crc_a;
    unsigned int crc_z;
    unsigned int crc_sum_a;
    unsigned int crc_sum_z;

    // Texte und Signaturen
    std::string utf8string;
    std::string signaturasciistring;
    std::string asciiueberschrift;
    std::string asciisignatur;
    std::vector<std::string> utf8emoticonhashtagliste;

    // Baumblock-Zähler
    int intanzahlbaumbloeckevorher;
    int intanzahlbaumbloeckenachher;
    int intanzahlbaumbloeckehier;

    unsigned int crcbaumbloeckehier;

    // Zeiger auf vorherige Blöcke für Baumstruktur
    std::vector<std::shared_ptr<CrcData>> vorherigeBloecke;

    // Konstruktor
    CrcData();

    // Methoden
    void clear();
    void print() const;
};

#endif // CRC_STRUCT_H
