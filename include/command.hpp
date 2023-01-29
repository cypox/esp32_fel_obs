#pragma once

#include <WiFi.h>
#include <WiFiUdp.h>


class Command {
public:
  Command(int);
  static void server_loop(void*);
  WiFiUDP* get_server_address();

private:
  WiFiUDP _udp_server;
};
