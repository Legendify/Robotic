#include <PIDLoop.h>
#include <Pixy2.h>
#include <Pixy2CCC.h>
#include <Pixy2I2C.h>
#include <Pixy2Line.h>
#include <Pixy2SPI_SS.h>
#include <Pixy2UART.h>
#include <Pixy2Video.h>
#include <TPixy2.h>

// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header
//
// This sketch is a good place to start if you're just getting started with
// Pixy and Arduino.  This program simply prints the detected object blocks
// (including color codes) through the serial console.  It uses the Arduino's
// ICSP SPI port.  For more information go here:
// https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:hooking_up_pixy_to_a_microcontroller_-28like_an_arduino-29

#include <Pixy2.h>
Pixy2 pixy;
int i, area;
void area_xy() {
  for (i = 0; i < pixy.ccc.numBlocks; i++) {
    //      Serial.print("  block ");
    //      Serial.print(i);
    //      Serial.print(": ");
    pixy.ccc.getBlocks();
    int x = pixy.ccc.blocks[i].m_x;
    int y = pixy.ccc.blocks[i].m_x;
    // If there are detect blocks, print them!
    if (pixy.ccc.numBlocks) {
      Serial.print("Detected ");
      Serial.println(pixy.ccc.numBlocks);
      Serial.print("x: ");
      Serial.println(x);
      Serial.print("y: ");
      Serial.println(y);
      if (x > 0 && y > 0) {
        area = 1;
        Serial.print("Area:");
        Serial.println(area);
      }
      if (x < 0 && y > 0) {
        area = 2;
        Serial.print("Area:");
        Serial.println(area);
      }
      if (x < 0 && y < 0) {
        area = 3;
        Serial.print("Area:");
        Serial.println(area);
      }
      if (x > 0 && y < 0) {
        area = 4;
        Serial.print("Area:");
        Serial.println(area);
      }
    }
  }
}
// This is the main Pixy object
void setup() {

  Serial.begin(115200);
  Serial.print("Starting...\n");
  pixy.init();
}

void loop() {
  // grab blocks!
  area_xy();
}
