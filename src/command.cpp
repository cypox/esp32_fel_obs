#include "command.hpp"


Command::Command(int port)
{
  _udp_server.begin(port);
  Serial.printf("UDP server running on %s:%i \n", WiFi.localIP().toString().c_str(), port);
}

WiFiUDP* Command::get_server_address()
{
  return &_udp_server;
}

void Command::server_loop(void* parameters)
{
  WiFiUDP* udp_server = (WiFiUDP*)parameters;
  char packet_buffer[255];

  while (true)
  {
    int packetSize = udp_server->parsePacket();
    if (packetSize)
    {
      Serial.printf("Received %d bytes from %s, port %d\n", packetSize, udp_server->remoteIP().toString().c_str(), udp_server->remotePort());
      int len = udp_server->read(packet_buffer, 255);
      if (len > 0)
      {
        packet_buffer[len] = '\0';
      }
      Serial.printf("UDP packet contents: %s\n", packet_buffer);
    }
  }
}
