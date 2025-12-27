#include <iostream>
#include <vector>
#include <iomanip>

// CRC-4 "klasse" für einfaches Hin und Zurück
class CRC4 {
    uint8_t polynomial = 0x13; // 0b10011
public:
    CRC4() = default;

    uint8_t compute(const std::vector<uint8_t>& data) const {
        uint8_t crc = 0;
        for (auto byte : data) {
            crc ^= (byte << 4); // auf obere 4 Bits shiften
            for (int i = 0; i < 8; ++i) {
                crc = (crc & 0x80) ? ((crc << 1) ^ polynomial) : (crc << 1);
            }
        }
        return crc >> 4; // nur 4 Bits
    }

    bool verify(const std::vector<uint8_t>& data, uint8_t crc) const {
        return compute(data) == crc;
    }
};

int main() {
    CRC4 crc4;
    std::vector<uint8_t> data = {0xAB, 0xCD};
    uint8_t crc = crc4.compute(data);

    std::cout << "Daten: ";
    for(auto b : data) std::cout << std::hex << (int)b << " ";
    std::cout << "\nCRC-4: " << std::hex << (int)crc << std::endl;

    std::cout << "Verifikation: "
              << (crc4.verify(data, crc) ? "OK" : "FEHLER") 
              << std::endl;
}
