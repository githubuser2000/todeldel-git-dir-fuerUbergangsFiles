#!/usr/bin/env python3
class CRC4:
    def __init__(self, polynomial=0x13):
        self.polynomial = polynomial  # 0b10011

    def compute(self, data):
        crc = 0
        for byte in data:
            crc ^= (byte << 4)  # auf obere 4 Bits shiften
            for _ in range(8):
                crc = ((crc << 1) ^ self.polynomial) if (crc & 0x80) else (crc << 1)
                crc &= 0xFF  # nur 8 Bit
        return crc >> 4

    def verify(self, data, crc):
        return self.compute(data) == crc

data = [0xAB, 0xCD]
crc4 = CRC4()
crc = crc4.compute(data)

print("Daten:", [hex(b) for b in data])
print("CRC-4:", hex(crc))
print("Verifikation:", "OK" if crc4.verify(data, crc) else "FEHLER")
