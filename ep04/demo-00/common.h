#ifndef COMMON_H_
#define COMMON_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

namespace pnp {

constexpr int kBackLog = 5;

struct Options {};

inline void errHandling(const char* err_msg) {
  perror(err_msg);
  exit(EXIT_FAILURE);
}

void receive(const Options& opt);

void transmit(const Options& opt);

}  // namespace pnp

#endif  // COMMON_H_
