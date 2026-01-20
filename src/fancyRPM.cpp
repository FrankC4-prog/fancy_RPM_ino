#include "fancyRPM.h"

#include <FastLED.h>

using frankc4::fancy_rpm::color_f::RGB_t;
using frankc4::fancy_rpm::FancyRPM;
using frankc4::fancy_rpm::color_f::ColorFunctionClass;

FancyRPM::FancyRPM(ELM327 &elm327,
    CRGB *leds, int numLeds,
    ColorFunctionClass *colorFunctionptr):

    elm327(elm327),
    leds(leds),
    numLeds(numLeds),
    colorFunctionptr(colorFunctionptr) {}

void FancyRPM::_updateRpm() {

    static float recievedRpm;

    if (elm327.nb_rx_state == ELM_GETTING_MSG) return;

    if (elm327.nb_rx_state == ELM_SUCCESS)
        _updateLEDs((uint16_t)recievedRpm);
    else elm327.printError();
    
    recievedRpm = elm327.rpm();

}

void FancyRPM::_updateLEDs(uint16_t rpm) {

    RGB_t color = colorFunctionptr->f(rpm);

    for (int i = 0; i < numLeds; i++)
        leds[i].setRGB(color.red, color.green, color.blue);

    FastLED.show();
}

void FancyRPM::update() {

    _updateRpm();

}