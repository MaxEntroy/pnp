#ifndef COMMON_H_
#define COMMON_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

namespace pnp {

constexpr int kBackLog = 5;

struct Options {};

inline void errHandling(const char* err_msg) {
  perror(err_msg);
  exit(EXIT_FAILURE);
}

int acceptOrDie(uint16_t port);

}  // namespace pnp

#endif  // COMMON_H_
