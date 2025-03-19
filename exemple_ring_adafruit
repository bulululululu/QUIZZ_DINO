// https://learn.adafruit.com/micro-bit-lesson-3-neopixels-with-micro-bit/software

#include <Adafruit_NeoPixel.h>

const int numPixels = 24;
const int pixelPin = 2;

Adafruit_NeoPixel ring = Adafruit_NeoPixel(numPixels, pixelPin);
uint32_t foreground = ring.Color(0x00, 0x00, 0xFF); // r, g, b - blue
uint32_t background = ring.Color(0x10, 0x10, 0x10); // dim white

void setup() {
  ring.begin(); // start the NeoPixel display
}

void loop() {
  // blue dot circles around a white background (for PixelRing 24)
  for (int i = 0; i < numPixels; i++) {
    ring.setPixelColor(i, foreground); // set pixel i to foreground
    ring.show();                       // actually display it
    delay(50);                         // milliseconds 
    ring.setPixelColor(i, background); // set pixel to background before moving on
    ring.show(); 
  }
}
