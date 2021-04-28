#include "common.h"

#include <errno.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

namespace pnp {

namespace {

inline void errHandling(const char* err_msg) {
  perror(err_msg);
  exit(EXIT_FAILURE);
}

void acceptOrDie(uint16_t port);

}  // anonymous namespace

void receive(const Options& opt) {}

void transmit(const Options& opt) {}

namespace {

void acceptOrDie(uint16_t port) {
  // socket
  int sfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sfd < 0) {
    errHandling("socket");
  }

  struct sockaddr_in serv_addr;
  bzero(&serv_addr, sizeof(serv_addr));

  // bind
  // list
  // accept
}

}  // anonymous namespace

}  // namespace pnp;
