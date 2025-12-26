#include <iostream>
#include <string>
#include <vector>
#include <bitset>

std::string crc_to_emoticons(uint64_t crc, int crc_bits, int block_size = 4) {
    // Emoticon-Liste (16 Stück für 4-Bit-Blöcke)
    std::vector<std::string> emoticons = {"😀","😁","😂","🤣","😃","😄","😅","😆",
                                          "😉","😊","😋","😎","😍","😘","😗","😙"};

    // Binärstring
    std::string bits;
    for (int i = crc_bits - 1; i >= 0; --i)
        bits += ((crc >> i) & 1) ? '1' : '0';

    std::string result;
    for (int i = 0; i < bits.size(); i += block_size) {
        std::string block = bits.substr(i, block_size);
        int num = std::stoi(block, nullptr, 2);
        result += emoticons[num % emoticons.size()];
    }

    return result;
}

int main() {
    std::cout << "CRC-8 0xD6 → " << crc_to_emoticons(0xD6, 8) << std::endl;
    std::cout << "CRC-16 0xABCD → " << crc_to_emoticons(0xABCD, 16) << std::endl;
    std::cout << "CRC-32 0xDEADBEEF → " << crc_to_emoticons(0xDEADBEEF, 32) << std::endl;
    return 0;
}
