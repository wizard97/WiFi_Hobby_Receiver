/*
* A basic library for communicating with a hobbyking wifi reciever
* By Aaron Wisner (daw268@cornell.edu)
*/

#ifndef Wifi_Hobby_Reciever
#define Wifi_Hobby_Reciever

#define SERVER_PORT_NUM 8899
#define MAX_STR_LEN 20
#define CONNECT_TIMEOUT 10000

// If using ESP8266, use built in wifi, otherwise assume wifi shield
#ifdef ARDUINO_ARCH_ESP8266
    #include <ESP8266WiFi.h>
#else
    #include <WiFi.h>
#endif

#include "Arduino.h"
#include <SPI.h>
#include <String.h>


class WifiHobbyReceiver
{

public:
    WifiHobbyReceiver(const char* ssid, const char* pass);
    bool begin();
    bool write(uint8_t ch1, uint8_t ch2, uint8_t ch3, uint8_t ch4);
    void stop();
    WiFiClient &getClient();

    static const uint8_t header[];
    static IPAddress serverAddress;
private:
    uint8_t _generateChecksum(uint8_t *buf, uint8_t len);
    bool _send(uint8_t *buf, uint8_t len);

    WiFiClient client;
    char _ssid[MAX_STR_LEN];
    char _pass[MAX_STR_LEN];
};

#endif
