#include "fancyRPM.h"

using fkc4::fancy_rpm::FancyRPM;

FancyRPM::FancyRPM(ELM327 &elm327,
    CRGB *leds, int numLeds):

    elm327(elm327),
    leds(leds),
    numLeds(numLeds),
    _color(0, 0, 0) {}

void FancyRPM::_updateRpm() {

    
    float tempRPM = elm327.rpm();

    if (elm327.nb_rx_state == ELM_SUCCESS)
    {
        uint16_t rpm = (uint32_t)tempRPM;
        _updateColor(rpm);
    }
    else if (elm327.nb_rx_state != ELM_GETTING_MSG)
        elm327.printError();

}

void FancyRPM::update() {

    _updateRpm();

}

uint8_t fkc4::fancy_rpm::rpmMap(uint16_t rpm, uint16_t maxRpm) {
    return (uint8_t)map(rpm, 0, maxRpm, 0, 255);
}