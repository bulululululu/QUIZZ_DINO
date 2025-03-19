//https://app.cirkitdesigner.com/project/9a104131-c955-4194-b21f-47da65e28d06

#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 72 // 6 rings * 12 LEDs per ring

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

void loop() {
  for(int brightness = 0; brightness < 256; brightness++) {
    setAllPixelsColor(255, 255, 0, brightness); // Yellow color with varying brightness
    delay(10);
  }
  for(int brightness = 255; brightness >= 0; brightness--) {
    setAllPixelsColor(255, 255, 0, brightness); // Yellow color with varying brightness
    delay(10);
  }
}

void setAllPixelsColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness) {
  for(int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color((red * brightness) / 255, (green * brightness) / 255, (blue * brightness) / 255));
  }
  pixels.show();
}
