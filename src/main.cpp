#include <Arduino.h>

#include "network.hpp"
#include "command.hpp"
#include "peripheral.hpp"
#include "rtos_tasks.hpp"

#define AP_SSID "Altair"
#define AP_PASS "PtS4LzLxjpepE4w67N"
#define UDP_CLIENT_PORT 9919
#define LED_BUILTIN 33


void setup() {
  Serial.begin(115200);
  Serial.println("Serial communication established");

  init_wifi(AP_SSID, AP_PASS, false);

  Command cmd_server(UDP_CLIENT_PORT);
  create_command_task(cmd_server, 16384, 2, ARDUINO_RUNNING_CORE);

  create_lights_task(LED_BUILTIN, 1024, 2, ARDUINO_RUNNING_CORE);
}

void loop() {
}
