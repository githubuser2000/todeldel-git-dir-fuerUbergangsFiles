#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

struct CrcData {
    uint32_t crc_a = 0;
    uint32_t crc_z = 0;
    uint32_t crc_sum_a = 0;
    uint32_t crc_sum_z = 0;

    std::string utf8string;
    std::string signaturasciistring;
    std::string asciiueberschrift;
    std::string asciisignatur;

    std::vector<std::string> utf8emoticonhashtagliste;

    int intanzahlbaumbloeckevorher = 0;
    int intanzahlbaumbloeckenachher = 0;
    int intanzahlbaumbloeckehier = 0;

    uint32_t crcbaumbloeckehier = 0;

    // Methoden inline definieren
    void clear() {
        crc_a = crc_z = crc_sum_a = crc_sum_z = 0;
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

    void print() const {
        std::cout << "CRC_A: " << crc_a << "\n";
        std::cout << "CRC_Z: " << crc_z << "\n";
        std::cout << "CRC_SUM_A: " << crc_sum_a << "\n";
        std::cout << "CRC_SUM_Z: " << crc_sum_z << "\n";
        std::cout << "UTF8 String: " << utf8string << "\n";
        std::cout << "Signature ASCII: " << signaturasciistring << "\n";
        std::cout << "ASCII Überschrift: " << asciiueberschrift << "\n";
        std::cout << "ASCII Signatur: " << asciisignatur << "\n";
        std::cout << "Emoticon Hashtags: ";
        for(const auto &s : utf8emoticonhashtagliste) std::cout << s << " ";
        std::cout << "\n";
        std::cout << "Baumblöcke vorher: " << intanzahlbaumbloeckevorher << "\n";
        std::cout << "Baumblöcke nachher: " << intanzahlbaumbloeckenachher << "\n";
        std::cout << "Baumblöcke hier: " << intanzahlbaumbloeckehier << "\n";
        std::cout << "CRC Baumblock hier: " << crcbaumbloeckehier << "\n";
    }
};
#ifdef ENABLE_THIS_MAIN
int main() {
    CrcData data;
    data.crc_a = 123;
    data.utf8string = "Hallo 🌍";
    data.utf8emoticonhashtagliste = {"#fun", "#code"};
    data.print();
    return 0;
}
#endif
