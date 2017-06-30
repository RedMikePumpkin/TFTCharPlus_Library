/*
  TFTCharPlus.h - Library for printing custom text on a TFT screen
  Created by RedMikePumpkin, June 30, 2017
  v1.0.0
  Licensed under a MIT License
*/

#include "Arduino.h"
#include "TFTCharPlus.h"

TFTCharPlus::begin(TFT startTFT) {
  tft = startTFT;
}

void TFTCharPlus::changeUsedTFT(TFT newTFT) {
  tft = newTFT;
}

void TFTCharPlus::setCharColor(uint8_t r, uint8_t g, uint8_t b) {
  tft.stroke(r, g, b);
  tft.fill(r, g, b);
}

void TFTCharPlus::setCharSize(uint8_t size) {
  textSize = size;
}

void TFTCharPlus::drawChar(byte data1, byte data2, byte data3, byte data4, byte data5, uint8_t xpos, uint8_t ypos) {
  byte data[5] = {data1, data2, data3, data4, data5};
  for (uint8_t x = 0; x < 5; x++) {
    for (uint8_t y = 0; y < 8; y++) {
      if (bitRead(data[x], 7 - y)) {
        tft.rect(x*textSize+xpos, y*textSize+ypos, textSize, textSize);
      }
    }
  }
}
