#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>

#include "common.h"
#include "ttcp_proto.h"

namespace pnp {

void receive(const Options& opt) {
  int peer_sfd = acceptOrDie(opt.port);

  struct SessionMessage session = {0, 0};
  int nr = tcpRead(peer_sfd, &session, sizeof(SessionMessage));
  assert(nr == sizeof(SessionMessage));
  session.number = ntohl(session.number);
  session.length = ntohl(session.length);

  PayloadMessage* payload = static_cast<PayloadMessage*>(malloc(sizeof(PayloadMessage) + session.length));
  assert(payload != nullptr);

  for (int i = 0; i < session.number; ++i) {
    nr = tcpRead(peer_sfd, &payload->length, sizeof(payload->length));
    assert(nr == sizeof(payload->length));
    payload->length = ntohl(payload->length);

    assert(payload->length == session.length);

    nr = tcpRead(peer_sfd, payload->data, payload->length);
    assert(nr == payload->length);

    uint32_t ack = htonl(payload->length);
    write(peer_sfd, &ack, sizeof(int));
  }

  free(payload);
  close(peer_sfd);
}

}  // namespace pnp

int main(void) {
  pnp::Options opt;
  pnp::receive(opt);
  return 0;
}
