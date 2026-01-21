#include <FastLED.h>
#include <WiFi.h>
#include <fancyRPM.h>

using fkc4::fancy_rpm::FancyRPM;

// ELM327 definitions
#define ELM_TIMEOUT 2000

// FastLED definitions
#define LED_PIN     8
#define COLOR_ORDER GRB
#define CHIPSET     WS2812
#define NUM_LEDS    30
#define BRIGHTNESS  255

DEFINE_GRADIENT_PALETTE(fiestaGP) { // defines a gradient palette
    0,      0,      255,    0,      // 0    RPM -> Green
    64,     0,      0,      255,    // 1000 RPM -> Blue
    96,     128,    0,      128,    // 1500 RPM -> purple
    128,    128,    128,    128,    // 2000 RPM -> white
    255,    255,    0,      0,      // 4000 RPM -> Red
};

// FancyRPM definitions
#define MAX_RPM 4000

// WiFi global
WiFiClient client;

// ELM327 global
ELM327 elm327;

// FastLed global
CRGB leds[NUM_LEDS];

// FancyRPM global
FancyRPM *fancyRpm;

void initWiFi() {

    const char* ssid = "WiFi_OBDII";
    IPAddress server = IPAddress(192, 168, 0, 10);

    Serial.begin(115200);

    // Connecting to ELM327 WiFi
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid);
    
    while ((WiFi.status() != WL_CONNECTED) || (WiFi.localIP() == IPAddress(0, 0, 0, 0))) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("Connected to Wifi");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    if (client.connect(server, 35000))
        Serial.println("connected");
    else
    {
        Serial.println("connection failed");
        exit(-1);
    }
}

void initLeds() {

    FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    
    FastLED.setBrightness( BRIGHTNESS );

}

void setup() {

    delay(3000);

    initLeds();

    initWiFi();

    elm327.begin(client, false, ELM_TIMEOUT);

    fancyRpm = FancyRPM::createFancyRpm(elm327, leds, NUM_LEDS, CRGBPalette16(fiestaGP), MAX_RPM);

}

void loop() {

    fancyRpm->update();

}