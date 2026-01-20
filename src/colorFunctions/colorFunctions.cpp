#include "colorFunctions.h"

using frankc4::fancy_rpm::color_f::MyGasolineFiesta;
using frankc4::fancy_rpm::color_f::RGB_t;

RGB_t MyGasolineFiesta::f(uint16_t rpm) {
    RGB_t color;
    if (rpm <= 1000) {
        color.blue = 0;
        color.green = ((1000 - rpm) * 255) / (1000 - 0);
        color.blue = ((rpm - 0) * 255) / (1000 - 0);
    } else if (rpm <= 1500) {
        color.blue = ((rpm - 1000) * 255) / (1500 - 1000);
        color.green = 0;
        color.blue = 255;
    } else if (rpm <= 2000) {
        color.blue = 255;
        color.green = ((rpm - 1500) * 255) / (2000 - 1500);
        color.blue = 255;
    } else if (rpm <= 3000) {
        color.blue = 255;
        color.green = ((3000 - rpm) * 255) / (3000 - 2000);
        color.blue = ((3000 - rpm) * 255) / (3000 - 2000);
    } else {
        color.blue = 255;
        color.green = 255;
        color.blue = 255;
    }
    return color;
}