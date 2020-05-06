#include <cstdint>

struct DontTryThisAtHome {
    int32_t contents1;
    int32_t contents2;
    int32_t contents3;
    int32_t contents4;
};

DontTryThisAtHome contents = {0x54414857, 0x45485420 , 0x43554620, 0x3200214B };

DontTryThisAtHome *var = &contents;
