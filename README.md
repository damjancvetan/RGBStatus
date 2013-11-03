RGBStatus
=============

This is Arduino library for working with RGB LED for your status codes/messages.

Installation
-------

Just copy the `RGBTools` folder to the `libraries` folder of your Arduino-IDE.

Usage
------------

```c++
#include <RGBStatus.h>
 
// Set pins for Red, Green, Blue
RGBStatus statusRGB(47, 4, 5);
 
void setup(){
	statusRGB.test();
	statusRGB.setMode(STATUS_NORMAL);
	
	statusRGB.setColor(255, 255, 0);
}
 
void loop(){
  // Your code
}
```

Author
------------

Damjan Cvetan (http://www.cvetan.net)