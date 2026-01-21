#ifndef FKC4_FANCY_RPM_GP
    #define FKC4_FANCY_RPM_GP

    #include <colorutils.h>

    DEFINE_GRADIENT_PALETTE(fkc4GasolineFiesta) {
        0,      0,      255,    0,      // 0    RPM -> Green
        64,     0,      0,      255,    // 1000 RPM -> Blue
        96,     128,    0,      128,    // 1500 RPM -> purple
        128,    128,    128,    128,    // 2000 RPM -> white
        255,    255,    0,      0,      // 4000 RPM -> Red
    };

#endif