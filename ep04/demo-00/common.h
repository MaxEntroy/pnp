#ifndef COMMON_H_
#define COMMON_H_

#include <cstdint>

namespace pnp {

// TTCP Request protocal
struct SessionMessage {
  int32_t number;
  int32_t length;
} __attribute__ ((__packed__));

struct PayloadMessage {
  int32_t length;
  char data[0];
};

// TTCP Response protocal is just the length of PayloadMessage

struct Options {};

void receive(const Options& opt);

void transmit(const Options& opt);

}  // namespace pnp

#endif
