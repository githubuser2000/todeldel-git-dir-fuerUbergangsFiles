#include "crc_struct.h"

// Konstruktor: initialisiert alle Werte auf Null
CrcData::CrcData() {
    clear();
}

// Setzt alle Werte zurück
void CrcData::clear() {
    crc_a = 0;
    crc_z = 0;
    crc_sum_a = 0;
    crc_sum_z = 0;

    utf8string.clear();
    signaturasciistring.clear();
    asciiueberschrift.clear();
    asciisignatur.clear();
    utf8emoticonhashtagliste.clear();

    intanzahlbaumbloeckevorher = 0;
    intanzahlbaumbloeckenachher = 0;
    intanzahlbaumbloeckehier = 0;

    crcbaumbloeckehier = 0;
}

// Gibt alle Werte auf der Konsole aus
void CrcData::print() const {
    std::cout << "CRC_A: " << crc_a << "\n";
    std::cout << "CRC_Z: " << crc_z << "\n";
    std::cout << "CRC_SUM_A: " << crc_sum_a << "\n";
    std::cout << "CRC_SUM_Z: " << crc_sum_z << "\n";
    std::cout << "UTF8 String: " << utf8string << "\n";
    std::cout << "Signature ASCII: " << signaturasciistring << "\n";
    std::cout << "ASCII Überschrift: " << asciiueberschrift << "\n";
    std::cout << "ASCII Signatur: " << asciisignatur << "\n";

    std::cout << "Emoticon Hashtags: ";
    for(size_t i = 0; i < utf8emoticonhashtagliste.size(); ++i) {
        std::cout << utf8emoticonhashtagliste[i];
        if(i + 1 != utf8emoticonhashtagliste.size()) std::cout << ", ";
    }
    std::cout << "\n";

    std::cout << "Baumblöcke vorher: " << intanzahlbaumbloeckevorher << "\n";
    std::cout << "Baumblöcke nachher: " << intanzahlbaumbloeckenachher << "\n";
    std::cout << "Baumblöcke hier: " << intanzahlbaumbloeckehier << "\n";
    std::cout << "CRC Baumblock hier: " << crcbaumbloeckehier << "\n";
}
