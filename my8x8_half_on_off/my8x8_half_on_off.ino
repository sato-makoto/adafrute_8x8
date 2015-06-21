/*
from Adafrute I2C LED matrix8x8 example.
https://github.com/adafruit/Adafruit-LED-Backpack-Library
*/

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix ();

void setup ()
{
  matrix.begin (0x70);
}

static const int all_on = B11111111;
static const uint8_t PROGMEM 
  every_bmp[] =
  { all_on, all_on, all_on, all_on,
    all_on, all_on, all_on, all_on };
   
void loop ()
{
  matrix.clear ();
  matrix.drawBitmap (0, 0, every_bmp, 8, 8, LED_ON);
  matrix.writeDisplay ();
  delay (500);
  matrix.drawBitmap (0, 0, every_bmp, 8, 8, LED_OFF);
  matrix.writeDisplay ();
  delay (500);
}
