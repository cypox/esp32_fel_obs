#include "command.hpp"

#include <lwip/sockets.h>
#include <lwip/netdb.h>
#include <errno.h>


Command::Command(IPAddress address, uint16_t server_port)
{
  char* tx_buffer = new char[1460];
  if(!tx_buffer){
    log_e("could not create tx buffer: %d", errno);
  }

  if ((udp_server=socket(AF_INET, SOCK_DGRAM, 0)) == -1){
    log_e("could not create socket: %d", errno);
  }

  int yes = 1;
  if (setsockopt(udp_server,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(yes)) < 0) {
      log_e("could not set socket option: %d", errno);
  }

  struct sockaddr_in addr;
  memset((char *) &addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(server_port);
  addr.sin_addr.s_addr = (in_addr_t)address;
  if(bind(udp_server , (struct sockaddr*)&addr, sizeof(addr)) == -1){
    log_e("could not bind socket: %d", errno);
  }
  fcntl(udp_server, F_SETFL, O_NONBLOCK);
  Serial.printf("UDP server running on %s:%i \n", address.toString().c_str(), server_port);
}

int Command::get_udp_socket() const
{
  return udp_server;
}

void Command::server_loop(void* parameters)
{
  int udp_server = *((int*)parameters);

  IPAddress remote_ip;
  uint16_t remote_port;
  char * buf = new char[1461]; // extra byte for '\0'

  while (true)
  {
    struct sockaddr_in si_other;
    int slen = sizeof(si_other) , len;
    len = recvfrom(udp_server, buf, 1460, MSG_DONTWAIT, (struct sockaddr *) &si_other, (socklen_t *)&slen);
    if (len == -1) continue;
    remote_ip = IPAddress(si_other.sin_addr.s_addr);
    remote_port = ntohs(si_other.sin_port);
    if (len > 0) {
      buf[len] = '\0';
      Serial.printf("Received %d bytes from %s, port %d\n", len, remote_ip.toString().c_str(), remote_port);
      Serial.printf("UDP packet contents: %s\n", buf);
    }
  }

  delete[] buf;
}
