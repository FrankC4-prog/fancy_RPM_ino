#include "fancyRPM.h"

namespace fkc4::fancy_rpm {

    class _FancyRPMpalette_t: public FancyRPM {

        friend FancyRPM * FancyRPM::createFancyRpm(
            ELM327 &elm327,
            CRGB *leds,
            int numLeds,
            CRGBPalette16 palette,
            uint16_t maxRpm);

        private:

            CRGBPalette16 palette;
            uint16_t maxRpm;

            void _updateColor(uint16_t rpm);

            _FancyRPMpalette_t(
                ELM327 &elm327,
                CRGB *leds,
                int numLeds,
                CRGBPalette16 palette,
                uint16_t maxRpm);

    };

    FancyRPM * FancyRPM::createFancyRpm(
        ELM327 &elm327,
        CRGB *leds,
        int numLeds,
        CRGBPalette16 palette,
        uint16_t maxRpm)
    { return new _FancyRPMpalette_t(elm327, leds, numLeds, palette, maxRpm); }

    void _FancyRPMpalette_t::_updateColor(uint16_t rpm) {

        static uint8_t curIndex = 255;
        uint8_t tempIndex = (uint8_t)map(rpm, 0, maxRpm, 0, 255);

        // if the index is not changed there is no need to update leds
        if (tempIndex == curIndex) return;

        curIndex = tempIndex;

        _color = ColorFromPalette(palette, curIndex, LINEARBLEND_NOWRAP);

        _updateLEDs();

    }

    _FancyRPMpalette_t::_FancyRPMpalette_t(
        ELM327 &elm327,
        CRGB *leds,
        int numLeds,
        CRGBPalette16 palette,
        uint16_t maxRpm):
    FancyRPM(elm327, leds, numLeds) {
        this->palette = palette;
        this->maxRpm = maxRpm;
    }
}