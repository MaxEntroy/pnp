#ifndef COMMON_H_
#define COMMON_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <string>

namespace pnp {

constexpr int kBackLog = 5;

struct Options {
  std::string ip = "127.0.0.1";
  uint16_t port = 13245;
  int length = 128;
  int number = 1024;
};

inline void errHandling(const char* err_msg) {
  perror(err_msg);
  exit(EXIT_FAILURE);
}

int tcpRead(int sfd, void* buf, int length);

int tcpWrite(int sfd, void* buf, int length);

int acceptOrDie(uint16_t port);

}  // namespace pnp

#endif  // COMMON_H_
