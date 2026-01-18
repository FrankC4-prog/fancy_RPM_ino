/*
    arduino IDE will ignore everything outside src if src folder is
    present. I'm putting the real header here to make the library
    compatible with platformIO/pioArduino, legacy C++ and industry
    standard while still be compatible with the Arduino IDE
*/

#ifndef FANCY_RPM_H
    #define FANCY_RPM_H

    #include <cstdint>

    namespace frankc4::fancy_rpm {

        class RGB_t {
            public:
                uint8_t red;
                uint8_t green;
                uint8_t blue;
        };

        class RGBW_t : RGB_t {
            public:
                uint8_t white;
        };
    };
    
#endif