#ifndef COLOR_FUNCTIONS_H
    #define COLOR_FUNCTIONS_H

    #include <crgb.h>
    
    namespace frankc4::fancy_rpm::color_f {

        /*
            typedef struct {
            uint8_t red;
            uint8_t green;
            uint8_t blue;
            } RGB_t;
            
            Description:
            ------------
            simple struct used for the output of color functions
        */
        typedef struct {
            uint8_t red;
            uint8_t green;
            uint8_t blue;
        } RGB_t;

        /*
            class ColorFunctionClass

            Description:
            ------------
            virtual class for every concrete function class
            to inherit

            Members:
            --------
            virtual RGB_t ColorFunctionClass::f(uint16_t rpm);

            Usage:
            ------
            extend this class by implementing f
        */
        class ColorFunctionClass {

            public:

                /*
                    virtual void f(uint16_t rpm, RGB_t *color)
                    
                    Description:
                    ------------
                    the function to override when defining subclasses.
                    you just calculate red, green, and blue based on
                    rpm and return it

                    Inputs:
                    -------
                    rpm

                    Outputs:
                    --------
                    CRGB
                */
                virtual RGB_t f(uint16_t rpm);
        };

        /*
            class MyGasolineFiesta: public ColorFunctionClass

            Built for my Fiesta and liking:
            ------------
            average car diesel engine, starts green at 0, goes to blue
            at 1000, then purple, magenta and white on 2000, turning
            yellow, orange at 3000 and red from 4000 and beyond
        */
        class MyGasolineFiesta : public ColorFunctionClass {
            public: RGB_t f(uint16_t rpm);
        };
        
    }

#endif