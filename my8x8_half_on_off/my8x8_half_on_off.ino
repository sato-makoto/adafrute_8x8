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
static const int half_on1 = B10101010;
static const int half_on2 = B01010101;

static const uint8_t PROGMEM 

// every_bmp1 light like:
// O _ O _ O _ O _
// _ O _ O _ O _ O
// O _ O _ O _ O _
// O _ O _ O _ O _
// _ O _ O _ O _ O
// _ O _ O _ O _ O
// O O O O O O O O
// O _ O _ O _ O _

  every_bmp1[] =
  { half_on1, half_on2, half_on1, half_on1,
    half_on2, half_on2, all_on, half_on1},

  every_bmp2[] =
  { half_on2, half_on1, half_on2, half_on1,
    half_on2, half_on1, half_on2, half_on1 };
   
void loop ()
{
  matrix.clear ();
  matrix.drawBitmap (0, 0, every_bmp1, 8, 8, LED_ON);
  matrix.writeDisplay ();
  delay (1500);

  matrix.clear();
  matrix.drawBitmap (0, 0, every_bmp2, 8, 8, LED_ON);
  matrix.writeDisplay ();
  delay (500);
}
