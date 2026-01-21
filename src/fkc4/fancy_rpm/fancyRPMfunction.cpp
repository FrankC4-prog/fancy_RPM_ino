#include "fancyRPM.h"

namespace fkc4::fancy_rpm {

    class _FancyRPMfunction_t: public FancyRPM {

        friend FancyRPM * FancyRPM::createFancyRpm(
            ELM327 &elm327,
            CRGB *leds,
            int numLeds,
            RPMcolorMapper colorMapper);
        
        private:

            RPMcolorMapper colorMapper;

            void _updateColor(uint16_t rpm);

            _FancyRPMfunction_t(
                ELM327 &elm327,
                CRGB *leds,
                int numLeds,
                RPMcolorMapper colorMapper);

    };

    FancyRPM * FancyRPM::createFancyRpm(
        ELM327 &elm327,
        CRGB *leds,
        int numLeds,
        RPMcolorMapper colorMapper)
    { return new _FancyRPMfunction_t(elm327, leds, numLeds, colorMapper); }

    void _FancyRPMfunction_t::_updateColor(uint16_t rpm) {

        Serial.println("hello from updatecolor function");

        CRGB color = colorMapper(rpm);

        if (color == _color) return;

        _color = color;
        _updateLEDs();
    }

    _FancyRPMfunction_t::_FancyRPMfunction_t(
        ELM327 &elm327,
        CRGB *leds,
        int numLeds,
        RPMcolorMapper colorMapper):
    FancyRPM(elm327, leds, numLeds) {
        this->colorMapper = colorMapper;
    }
}