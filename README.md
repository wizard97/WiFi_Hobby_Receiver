# Arduino WiFi Hobby Receiver Library
A simply library for communicating with [Hobbyking's 4 Channel RC WiFi receiver](http://www.hobbyking.com/hobbyking/store/__21430__Hobbyking_IOS_Android_4CH_WiFi_Receiver.html)

I reverse engineered the protocol for communicating with these receivers and created an Arduino library for writing to them over WiFi. Look in the examples folder for an example sketch, be sure to replace the SSID and PASS with your receiver's credentials.

## Supported Platforms
The library uses the [Arduino Wifi Library](https://www.arduino.cc/en/Reference/WiFi) behind the scenes. Any library that provides the same API should work.

#### Arduino WiFi Shield
This Library is compatible with the WiFi shield. The library will automatically assume you are using the WiFi shield if you are not using the ESP8266 board.

#### ESP8266
This Library is compatible with the ESP8266. The library will automatically assume you are using the built in WiFi on the ESP8266 (not the Arduino WiFi shield).

## Methods

### Constructor
```c++
WifiHobbyReceiver(const char* ssid, const char* pass)
```
Create a WifiHobbyReceiver object with a particular SSID and password.
#### Arguments:
<dl>
  <dt>ssid: </dt><dd>The SSID of the reciever (ex: "ezc  wifi  024"). PAY ATTENTION TO THE SPACES IN THE SSID!</dd>
  <dt>pass: </dt><dd>The password, usually is 8 of the same digit. Should be on the back of the receiver (ex: "44444444").</dd>
</dl>

## begin()
```c++
bool begin()
```
Try and connect to the receiver and setup the necessary TCP connection.
#### Return:
True on success

## stop()
```c++
void stop()
```
Shut down the TCP connection.
#### Return:
Void

## write()
```c++
bool write(uint8_t ch1, uint8_t ch2, uint8_t ch3, uint8_t ch4)
```
Write the specified value to each chanel of the receiver.
#### Arguments:
<dl>
  <dt>ch1-ch4: </dt><dd>The value to write to each chanel, should be between 0-64.</dd>
</dl>
#### Return:
True on success
