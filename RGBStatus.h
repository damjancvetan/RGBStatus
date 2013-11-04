//
//  RGBStatus.h
//  RGBStatus
//
//  Created by Damjan Cvetan on 11/3/13.
//  Copyright (c) 2013 Damjan Cvetan, damjan@cvetan.net. All rights reserved.
//

#ifndef RGBStatus_h
#define RGBStatus_h

#include <Arduino.h>

#define TEST_DELAY 300

enum StatusMode {
  STATUS_NORMAL,
  STATUS_WORKING,
  STATUS_ERROR,
  STATUS_CONFIG
};

class RGBStatus {
public:
  RGBStatus(int pinRed, int pinGreen, int pinBlue);
  void on();
  void off();
  void setColor(int R, int G, int B);
  void setMode(StatusMode mode);
  void save();
  void restore();
  void test();
private:
  // Setup pins for colors
  int outRed, outGreen, outBlue;
  
  // Current colors
  int colorRed, colorGreen, colorBlue;
  
  // Save values
  int saveRed, saveGreen, saveBlue;
};

#endif
