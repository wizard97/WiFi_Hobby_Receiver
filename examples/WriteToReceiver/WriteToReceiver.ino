#include "WifiHobbyReceiver.h"
#include <String.h>

#define SSID "mynetwork"
#define PASS "aaronisawesome"

// Create 
WifiHobbyReceiver recv(SSID, PASS);


void setup() {
  Serial.begin(9600);
  Serial.println("Atempting to Connect to network");

  if(recv.begin()) {
    // success
    Serial.println("Connected to network and server");
  } else {
    // failed
    Serial.println("Failed to connect");
    while(1);
  }

  randomSeed(millis());
}

void loop() {
  
  // 4 channels
  uint8_t vals[4];

  for (int i=0; i < sizeof(vals); i++)
  {
    vals[i] = (uint8_t)random(0, 255);
    Serial.print(F("Writing: "));
    Serial.print(vals[i]);
    Serial.print(F(" to channel "));
    Serial.println(i);
  }
  if (recv.write(vals[0], vals[1], vals[2], vals[3])) {
    Serial.print(F("SUCCESS sending data"));
  } else {
    Serial.println(F("FAILED to send data"));
  }

  Serial.println();
  delay(3000);
}
