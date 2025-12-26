#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>

std::vector<std::string> EMOTICONS = {"😀","😁","😂","🤣","😃","😄","😅","😆",
                                      "😉","😊","😋","😎","😍","😘","😗","😙"};

// CRC-8 Berechnung
uint8_t crc8(const std::vector<uint8_t>& data, uint8_t poly = 0x07, uint8_t init = 0x00) {
    uint8_t crc = init;
    for (auto byte : data) {
        crc ^= byte;
        for (int i = 0; i < 8; i++) {
            if (crc & 0x80)
                crc = (crc << 1) ^ poly;
            else
                crc <<= 1;
        }
    }
    return crc;
}

// CRC → Emoticons
std::string crc_to_emoticons(uint64_t crc, int crc_bits, int block_size = 4) {
    std::string bits;
    for (int i = crc_bits - 1; i >= 0; --i)
        bits += ((crc >> i) & 1) ? '1' : '0';

    std::string result;
    for (int i = 0; i < bits.size(); i += block_size) {
        std::string block = bits.substr(i, block_size);
        int num = std::stoi(block, nullptr, 2);
        result += EMOTICONS[num % EMOTICONS.size()];
    }
    return result;
}

// Emoticons → CRC
uint64_t emoticons_to_crc(const std::string& emojis, int crc_bits, int block_size = 4) {
    std::string bits;
    for (size_t i = 0; i < emojis.size(); ++i) {
        std::string e = emojis.substr(i, 4); // Annahme 4 Byte pro Emoji
        auto it = std::find(EMOTICONS.begin(), EMOTICONS.end(), e);
        if (it != EMOTICONS.end()) {
            int idx = it - EMOTICONS.begin();
            bits += std::bitset<4>(idx).to_string();
        }
    }
    bits = bits.substr(0, crc_bits);
    return std::stoull(bits, nullptr, 2);
}

int main() {
    std::vector<uint8_t> data = {'H','e','l','l','o'};
    uint8_t crc = crc8(data);
    std::string emojis = crc_to_emoticons(crc, 8);
    uint64_t crc_back = emoticons_to_crc(emojis, 8);

    std::cout << "Daten: Hello" << std::endl;
    std::cout << "CRC: " << (int)crc << std::endl;
    std::cout << "Emojis: " << emojis << std::endl;
    std::cout << "CRC zurück: " << crc_back << std::endl;

    return 0;
}
