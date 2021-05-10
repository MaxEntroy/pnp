#ifndef TTCP_PROTO_H_
#define TTCP_PROTO_H_

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

}  // namespace pnp

#endif  // TTCP_PROTO_H_
