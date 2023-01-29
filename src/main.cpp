#include <Arduino.h>

#include "network.hpp"
#include "command.hpp"
#include "peripheral.hpp"
#include "rtos_tasks.hpp"

const char* AP_SSID = "Altair";
const char* AP_PASS = "PtS4LzLxjpepE4w67N";
const int UDP_CLIENT_PORT = 9919;
int LED_BUILTIN = 33;


void setup() {
  Serial.begin(115200);
  Serial.println("Serial communication established");

  init_wifi(AP_SSID, AP_PASS, false);

  Command cmd_server(WiFi.localIP(), UDP_CLIENT_PORT);
  int socket = cmd_server.get_udp_socket();
  create_command_task(&socket, 32768, 1, ARDUINO_RUNNING_CORE);

  create_lights_task(&LED_BUILTIN, 2048, 1, ARDUINO_RUNNING_CORE);
}

void loop() {
}
