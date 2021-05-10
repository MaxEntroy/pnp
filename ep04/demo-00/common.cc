#include "common.h"

#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <unistd.h>

namespace pnp {

namespace {

int acceptOrDie(uint16_t port);

}  // anonymous namespace

void receive(const Options& opt) {}

void transmit(const Options& opt) {}

namespace {

int acceptOrDie(uint16_t port) {
  // socket
  int listen_sfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (listen_sfd < 0) {
    errHandling("socket");
  }

  int yes = 1;
  if (setsockopt(listen_sfd, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<void*>(&yes), sizeof(yes)) < 0) {
    errHandling("setsockopt");
  }

  // bind
  struct sockaddr_in serv_addr;
  bzero(&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(port);
  if (bind(listen_sfd, reinterpret_cast<struct sockaddr*>(&serv_addr), sizeof(serv_addr)) < 0) {
    errHandling("bind");
  }

  // listen
  if (listen(listen_sfd, kBackLog) < 0) {
    errHandling("listen");
  }

  // accept
  struct sockaddr_in perr_addr;
  socklen_t perr_addr_len = 0;
  int perr_sfd = accept(listen_sfd, reinterpret_cast<struct sockaddr*>(&perr_addr), &perr_addr_len);
  if (perr_sfd < 0) {
    errHandling("accept");
  }

  close(listen_sfd);
  return perr_sfd;
}

}  // anonymous namespace

}  // namespace pnp;
