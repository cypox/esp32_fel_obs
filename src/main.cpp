#include <Arduino.h>

#include "network.hpp"
#include "command.hpp"

#define AP_SSID "Altair"
#define AP_PASS "PtS4LzLxjpepE4w67N"
#define UDP_CLIENT_PORT 9919


void setup() {
  init_wifi(AP_SSID, AP_PASS, false);
  Command cmd_server(UDP_CLIENT_PORT);
}

void loop() {
}
