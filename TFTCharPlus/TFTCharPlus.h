/*
  TFTCharPlus.h - Library for printing custom text on a TFT screen
  Created by RedMikePumpkin, June 30, 2017
  v1.0.0
  Licensed under a MIT License
*/

#ifndef TFTCharPlus_h
#define TFTCharPlus_h

#include "Arduino.h"

class TFTCharPlus {
  public:
    begin(TFT startTFT);
    void changeUsedTFT(TFT newTFT);
    void setCharColor(uint8_t r, uint8_t g, uint8_t b);
    void setCharSize(uint8_t size);
    void drawChar(byte data1, byte data2, byte data3, byte data4, byte data5, uint8_t xpos, uint8_t ypos);
  private:
    uint8_t textSize = 1;
    TFT tft = TFT(0, 0, 0);
}

#endif
