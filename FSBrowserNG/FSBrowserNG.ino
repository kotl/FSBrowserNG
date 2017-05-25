
// Disable AP button. You can override APenabled behavior in this case.
// #define AP_ENABLE_BUTTON -1

// Force ARDUINO Ota always enabled
// #define FS_WEBSERVER_ARDUINO_OTA

// Enable DEBUG mode
// #define FS_WEBSERVER_DEBUG

#include <ESP8266WiFi.h>
#include "FS.h"
#include <WiFiClient.h>
#include <TimeLib.h>
#include <NtpClientLib.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266mDNS.h>
#include <Ticker.h>
#include <ArduinoJson.h>
#include "FSWebServerLib.h"
#include <Hash.h>

/* Implement your own logic for AP enabled mode. 

class MyServer : public AsyncFSWebServer {
public:
  MyServer(uint16_t port)  : AsyncFSWebServer(port) {}
protected:
  bool isAPEnabled();
};

bool MyServer::isAPEnabled() {
  return true;
}

MyServer ESPHTTPServer(80);
*/

AsyncFSWebServer ESPHTTPServer(80);

void setup() {
    // WiFi is started inside library
    SPIFFS.begin(); // Not really needed, checked inside library and started if needed
    ESPHTTPServer.begin(&SPIFFS);
    /* add setup code here */
}

void loop() {
    /* add main program code here */
    
    // DO NOT REMOVE. Attend OTA update from Arduino IDE
    ESPHTTPServer.handle();	
}
