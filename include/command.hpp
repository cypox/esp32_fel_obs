#pragma once

#include <Arduino.h>
#include <Udp.h>


class Command {
public:
  Command(IPAddress, uint16_t);
  static void server_loop(void*);

  int get_udp_socket() const;

private:
  int udp_server;
};
