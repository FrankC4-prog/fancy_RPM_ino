#include "fancyRPM.h"

#include <FastLED.h>

void fkc4::fancy_rpm::FancyRPM::_updateLEDs() {

    for (int i = 0; i < numLeds; i++) leds[i] = _color;
    FastLED.show();

}