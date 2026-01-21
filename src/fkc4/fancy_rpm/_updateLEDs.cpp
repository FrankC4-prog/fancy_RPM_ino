#include "fancyRPM.h"

#include <FastLED.h>

void fkc4::fancy_rpm::FancyRPM::_updateLEDs() {

    fill_solid(leds, numLeds, _color);

    FastLED.show();

}