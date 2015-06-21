/*
from Adafrute I2C LED matrix8x8 example.
https://github.com/adafruit/Adafruit-LED-Backpack-Library
*/

/*
One LED light moves through (1,1) to (8,8),
*/

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix ();

void setup ()
{
  matrix.begin (0x70);
  matrix.clear();
  matrix.writeDisplay();

}

 int col_row ;
 static const int lightdot = 128;
 // 128 == B100000000
 static const int none = 0;
 static const uint8_t PROGMEM
 mymap[] = {lightdot, none, none, none,
          none, none, none, none };


void loop()
{
 for(col_row = 0; col_row < 8; col_row++)
 {
    matrix.drawBitmap(col_row, col_row, mymap, 
      col_row+1, col_row+1, LED_ON);
    matrix.writeDisplay();
    delay(500);
    matrix.clear();
    matrix.writeDisplay();
 }
}
