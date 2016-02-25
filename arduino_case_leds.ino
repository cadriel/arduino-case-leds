/*
 * PC Case LEDS.
 * 
 * This project simply displays your led's in a predefined color.
 * 
 */
 
#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"

#define PIN 4
#define LED_COUNT 10
#define COLOR SNOW
#define BRIGHTNESS 10

// Create an instance of the Adafruit_NeoPixel class called "leds".
// That'll be what we refer to from here on...
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{

  // Start up the LED strip.
  leds.begin();

  // Reset our LED's. This turned them off and set's the default brightness.
  resetLEDS();

  // Loop through all of our defined LED's and set the defined color.
  for (int i=0; i<LED_COUNT; i++) {
    leds.setPixelColor(i, COLOR);
  }
  
  // Now, show the LED's.
  leds.show();
}

void loop(){}

// Sets all LEDs to off, but DOES NOT update the display;
// call leds.show() to actually turn them off after this.
void resetLEDS()
{
  for (int i=0; i<LED_COUNT; i++)
  {
    leds.setPixelColor(i, 0);
  }
  leds.setBrightness(BRIGHTNESS);
}

