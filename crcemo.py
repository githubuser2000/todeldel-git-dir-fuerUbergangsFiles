# CRC zu Emoticons
def crc_to_emoticons(crc: int, crc_bits: int, block_size: int = 4) -> str:
    # Emoticon-Liste (16 Stück für 4-Bit-Blöcke)
    emoticons = ["😀","😁","😂","🤣","😃","😄","😅","😆",
                 "😉","😊","😋","😎","😍","😘","😗","😙"]

    # Binärstring mit führenden Nullen
    bits = bin(crc)[2:].zfill(crc_bits)
    result = ""

    # Bits in Blöcke aufteilen
    for i in range(0, len(bits), block_size):
        block = bits[i:i+block_size]
        num = int(block, 2)
        result += emoticons[num % len(emoticons)]

    return result

# Beispiele
print("CRC-8 0xD6 →", crc_to_emoticons(0xD6, 8))       # 😘😅
print("CRC-16 0xABCD →", crc_to_emoticons(0xABCD, 16)) # 😗🤣😋😄
print("CRC-32 0xDEADBEEF →", crc_to_emoticons(0xDEADBEEF, 32)) # 😎😅😗🤣😋😅😄😆
