/*
    arduino IDE will ignore everything outside src if src folder is
    present. I'm putting the real header here to make the library
    compatible with platformIO/pioArduino, legacy C++ and industry
    standard while still be compatible with the Arduino IDE
*/

#ifndef FANCY_RPM_H
    #define FANCY_RPM_H

    #include <cstdint>
    #include <ELMduino.h>
    #include "colorFunctions/colorFunctions.h"

    namespace frankc4::fancy_rpm {

        using color_f::ColorFunctionClass;

        /*
            class FancyRPM

            Description:
            ------------
            FancyRPM main class, handles elm327 and leds istancies passively

            Usage:
            ------
            call the constructor to initialize, then run update() at loop
            or wherever and whenever you want to update, it's NON-BLOCKING
        */
        class FancyRPM {

            private:

                ELM327 &elm327;
                CRGB *leds;
                int numLeds;
                ColorFunctionClass *colorFunctionptr;

            public:

                /*
                    FancyRPM(ELM327 obj, CRGB *FastLED_leds_array, int numLeds, ColorFunctionClass *colorFunctionptr)
                */
                FancyRPM(ELM327 &elm327, CRGB *leds, int numLeds, ColorFunctionClass *colorFunctionptr);

                /*
                    internal
                */
                void _updateRpm();

                /*
                    internal
                */
                void _updateLEDs(uint16_t rpm);

                /*
                    void update()

                    Description:
                    ------------
                    NON-BLOCKING core of the library, call when you want
                */
                void update();

            };

    };
    
#endif