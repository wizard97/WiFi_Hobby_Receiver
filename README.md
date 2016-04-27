# Arduino WiFi Hobby Receiver Library
A simply library for communicating with [Hobbyking's 4 Channel RC WiFi receiver](http://www.hobbyking.com/hobbyking/store/__21430__Hobbyking_IOS_Android_4CH_WiFi_Receiver.html)

I reverse engineered the protocol for communicating with these receivers and created an Arduino library for writing to them over WiFi.

## Suported Platforms
The library uses the [Arduino Wifi Library](https://www.arduino.cc/en/Reference/WiFi) behind the scenes. Any library that provides the same API should work.

### Arduino WiFi Shield
This Library is compatible with the WiFi shield. To use, replace the `#include <ESP8266WiFi.h>` with `#include <WiFi.h>` at the top of the `WifiHobbyReceiver.h` file.

### ESP8266
This library works out of the box with the ESP8266 with no changes.
