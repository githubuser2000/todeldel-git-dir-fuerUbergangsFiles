# CRC-Emoticon Mapper

EMOTICONS = ["😀","😁","😂","🤣","😃","😄","😅","😆",
             "😉","😊","😋","😎","😍","😘","😗","😙"]

# CRC Berechnung (CRC-8 Beispiel)
def crc8(data: bytes, poly=0x07, init=0x00) -> int:
    crc = init
    for byte in data:
        crc ^= byte
        for _ in range(8):
            if crc & 0x80:
                crc = ((crc << 1) ^ poly) & 0xFF
            else:
                crc = (crc << 1) & 0xFF
    return crc

# CRC → Emoticons
def crc_to_emoticons(crc: int, crc_bits: int, block_size: int = 4) -> str:
    bits = bin(crc)[2:].zfill(crc_bits)
    result = ""
    for i in range(0, len(bits), block_size):
        block = bits[i:i+block_size]
        num = int(block, 2)
        result += EMOTICONS[num % len(EMOTICONS)]
    return result

# Emoticons → CRC
def emoticons_to_crc(emojis: str, crc_bits: int, block_size: int = 4) -> int:
    bits = ""
    for e in emojis:
        idx = EMOTICONS.index(e)
        bits += bin(idx)[2:].zfill(block_size)
    # nur die ersten crc_bits nehmen
    bits = bits[:crc_bits]
    return int(bits, 2)

# Beispiel
data = b"Hello"
crc = crc8(data)
emojis = crc_to_emoticons(crc, 8)
crc_back = emoticons_to_crc(emojis, 8)

print("Daten:", data)
print("CRC:", crc)
print("Emojis:", emojis)
print("CRC zurück:", crc_back)
