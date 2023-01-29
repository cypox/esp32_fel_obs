#include "network.hpp"


void init_wifi(const char* ssid, const char* passphrase, bool create_new_ap)
{
  if(create_new_ap) { // create own wifi network
    WiFi.softAP(ssid, passphrase);
  } else { // connect to existing network
    WiFi.mode(WIFI_STA); //Optional
    WiFi.begin(ssid, passphrase);
    Serial.println("Connecting to wifi network");

    while(WiFi.status() != WL_CONNECTED){
      Serial.print(".");
      delay(100);
    }

    Serial.println("Connected to the WiFi network");
    Serial.print("Local IP: ");
    Serial.println(WiFi.localIP());
  }
}
