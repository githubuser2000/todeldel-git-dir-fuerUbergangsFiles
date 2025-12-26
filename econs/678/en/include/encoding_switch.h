#pragma once

#ifdef ASCII_ONLY
    #define BOX_LINE "=============================================="
    #define ICON_INT "[INT]"
    #define ICON_REL "[RAT]"
#else
    #define BOX_LINE u8"¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿"
    #define ICON_INT u8"¿"
    #define ICON_REL u8"¿"
#endif
