#ifndef CRC_STRUCT_H
#define CRC_STRUCT_H

#include <string>
#include <vector>
#include <iostream>

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
