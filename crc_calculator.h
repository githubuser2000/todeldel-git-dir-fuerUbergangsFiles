#ifndef CRC_CALCULATOR_H
#define CRC_CALCULATOR_H

#include "crc_struct.h"
#include <cstdint>

namespace CRC {

// Berechnet CRC rekursiv über alle Blöcke (inkl. vorherige)
uint32_t computeCRC(const std::shared_ptr<CrcData> &data);

// Vergleicht mit Referenz und gibt aus
void checkCRC(const std::shared_ptr<CrcData> &data, uint32_t referenceCRC);

} // namespace CRC

#endif // CRC_CALCULATOR_H/
