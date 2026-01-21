#include <FastLED.h>
#include <WiFi.h>
#include <fancyRPM.h>
#include <RPM_gradient_palettes.h>

// i use the namespace, blame me
using fkc4::fancy_rpm::FancyRPM;

// WiFi definitions
#define SERVER_ADDR 192, 168, 0, 10
#define SSID "WiFi_OBDII"

// ELM327 definitions
#define ELM_TIMEOUT 2000

// FastLED definitions
#define LED_PIN     8
#define COLOR_ORDER GRB
#define CHIPSET     WS2812
#define NUM_LEDS    30
#define BRIGHTNESS  255

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

    const char* ssid = SSID;
    IPAddress serverAddr = IPAddress(SERVER_ADDR);

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

    if (client.connect(serverAddr, 35000))
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

    Serial.begin(115200);

    initLeds();

    initWiFi();

    elm327.begin(client, false, ELM_TIMEOUT);

    fancyRpm = FancyRPM::createFancyRpm(elm327, leds, NUM_LEDS, CRGBPalette16(avgGasolineGP), MAX_RPM);

}

void loop() {

    fancyRpm->update();

}