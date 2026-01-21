#ifndef FCK4_FANCY_RPM_H
    #define FCK4_FANCY_RPM_H

    #include <cstdint>
    #include <ELMduino.h>
    #include <colorutils.h>

    namespace fkc4::fancy_rpm {

        using RPMcolorMapper = CRGB (*)(uint16_t);

        /*
            uint8_t rpmMap(uint16_t rpm, uint16_t maxRpm)

            Description:
            ------------
            
            maps rpm from a [0 - maxRpm] range to a [0 - 255] range
        */
        uint8_t rpmMap(uint16_t rpm, uint16_t maxRpm);
        
        /*
            class FancyRPM

            Description:
            ------------
            FancyRPM main class, handles elm327 and leds istancies passively

            Usage:
            ------
            This is a virtual class, you need to istanciate either a FancyRPMfunction
            class or FancyRPMpalette class

        */
        class FancyRPM {

            private:

                ELM327 &elm327;
                CRGB *leds;
                int numLeds;

                void _updateRpm();

                virtual void _updateColor(uint16_t rpm) = 0;

            protected:

                CRGB _color;

                FancyRPM(ELM327 &elm327, CRGB *leds, int numLeds);

                void _updateLEDs();

            public:

                /*
                    void update()

                    Description:
                    ------------
                    NON-BLOCKING core of the library, call when you want
                */
                void update();

                /*
                    static FancyRPM * createFancyRpm(ELM327 &elm327, CRGB *leds, int numLeds, RPMcolorMapper colorMapper);

                    factory method, creates a FancyRPM obj that works with a simple color
                    function you can write yourself, logic will be different and slower
                    then working with a FastLED palette

                    How to write the function:
                    must return a CRGB that is the color and take uint16_t rpm as input

                    example:

                    CRGB f(uint16_t rpm) {
                        if ((rpm / 200) % 2) return CRGB::Black;
                        else return CRGB::White;
                    }
                    
                    a function that returns off and on color on alternating ranges of rpm

                    @param &elm327      reference to the INITIALIZED elm327 obj
                    @param *leds        reference to the leds array
                    @param numLeds      number of leds
                    @param colorMapper  your function
                */
                static FancyRPM * createFancyRpm(ELM327 &elm327, CRGB *leds, int numLeds, RPMcolorMapper colorMapper);

                /*
                    static FancyRPM * createFancyRpm(ELM327 &elm327, CRGB *leds, int numLeds, CRGBPalette16 palette, uint16_t maxRpm);

                    factory method, creates a FancyRPM obj that works with a FastLED palette,
                    logic will be different and faster then working with just a function

                    @param &elm327      reference to the INITIALIZED elm327 obj
                    @param *leds        reference to the leds array
                    @param numLeds      number of leds
                    @param palette      CRGBPalette16 color palette
                */
                static FancyRPM * createFancyRpm(ELM327 &elm327, CRGB *leds, int numLeds, CRGBPalette16 palette, uint16_t maxRpm);

        };

    };
    
#endif