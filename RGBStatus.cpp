//
//  RGBStatus.cpp
//  RGBStatus
//
//  Created by Damjan Cvetan on 11/3/13.
//  Copyright (c) 2013 Damjan Cvetan, damjan@cvetan.net. All rights reserved.
//

#include "RGBStatus.h"

// Setup pins for colors
int outRed, outGreen, outBlue;

// Current colors
int colorRed, colorGreen, colorBlue;

// Save values
int saveRed, saveGreen, saveBlue;

// Construct
RGBStatus::RGBStatus(int pinRed, int pinGreen, int pinBlue){
  outRed    = pinRed;
  outGreen  = pinGreen;
  outBlue   = pinBlue;
  colorRed  = colorGreen = colorBlue = 0;
  saveRed   = saveGreen  = saveBlue = 0;
  
  pinMode(outRed, OUTPUT);
  pinMode(outGreen, OUTPUT);
  pinMode(outBlue, OUTPUT);
}

void RGBStatus::on() {
  setColor(255,255,255);
}

void RGBStatus::off() {
  setColor(0,0,0);
}

void RGBStatus::save(){
  saveRed   = colorRed;
  saveGreen = colorGreen;
  saveBlue  = colorBlue;
}

void RGBStatus::restore(){
  setColor(saveRed, saveGreen, saveBlue);
}

// Set color
void RGBStatus::setColor(int R, int G, int B){
  if((R < 0 || R > 255) ||
     (G < 0 || G > 255) ||
     (B < 0 || B > 255)){
    if(Serial){
      Serial.println("RGBStatus: Unvalid RGB value!");
    }
    return;
  }

  colorRed    = R;
  colorGreen  = G;
  colorBlue   = B;
  
  analogWrite(outRed, colorRed);
  analogWrite(outGreen, colorGreen);
  analogWrite(outBlue, colorBlue);
}

// Set mode
void RGBStatus::setMode(StatusMode mode){
  switch (mode) {
    case STATUS_NORMAL:
      setColor(0, 255, 0);
      break;
    case STATUS_WORKING:
      setColor(0, 0, 255);
      break;
    case STATUS_ERROR:
      setColor(255, 0, 0);
      break;
    case STATUS_CONFIG:
      setColor(255, 255, 0);
      break;
    default:
      setColor(255,255,255);
      break;
  }
}

void RGBStatus::test(){
  setColor(255, 0, 0);
  delay(TEST_DELAY);
  setColor(0, 255, 0);
  delay(TEST_DELAY);
  setColor(0, 0, 255);
  delay(TEST_DELAY);
}