#include "WifiHobbyReceiver.h"

const uint8_t WifiHobbyReceiver::header[] = {85, 0, 11, 0};

IPAddress WifiHobbyReceiver::serverAddress(10, 10, 100, 254);


WifiHobbyReceiver::WifiHobbyReceiver(const char* ssid, const char* pass)
: client()
{
    strncpy(this->_ssid, ssid, MAX_STR_LEN);
    strncpy(this->_pass, pass, MAX_STR_LEN);
}


bool WifiHobbyReceiver::begin()
{
    int status = WL_IDLE_STATUS;
    unsigned long start = millis();

    while (status != WL_CONNECTED && millis() < start + CONNECT_TIMEOUT) {
      // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
      status = WiFi.begin(_ssid, _pass);
      if (status != WL_CONNECTED) delay(1000);
    }

    Serial.println("Calling connect");
    return (status == WL_CONNECTED) && client.connect(serverAddress, SERVER_PORT_NUM);

}


bool WifiHobbyReceiver::write(uint8_t ch1, uint8_t ch2, uint8_t ch3, uint8_t ch4)
{
    uint8_t buf[15];
    memcpy(buf, header, sizeof(header));

    uint8_t index = sizeof(header);
    buf[index++] = ch1;
    buf[index++] = ch2;
    buf[index++] = ch3;
    buf[index++] = ch4;
    buf[index++] = 255;
    buf[index++] = 255;
    buf[index] = _generateChecksum(buf, index);
    index++;

    return _send(buf, index);
}


void WifiHobbyReceiver::stop()
{
    client.stop();
}

uint8_t WifiHobbyReceiver::_generateChecksum(uint8_t *buf, uint8_t len)
{
    // If we declare this as a uint8_t, we can use overflow to do mod operation
    uint8_t checksum = 0;

    for (int i=0; i < len; i++)
    {
        checksum += buf[i];
    }

    return checksum;
}

bool WifiHobbyReceiver::_send(uint8_t *buf, uint8_t len)
{
    for (int i=0; i < len; i++)
    {
        if(!client.write(buf[i])) return false;
    }

    return true;
}

WiFiClient &WifiHobbyReceiver::getClient()
{
    return client;
}
