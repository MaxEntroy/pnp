#include <assert.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include "common.h"
#include "ttcp_proto.h"

namespace pnp {

void transmit(const Options& opt) {
  int sfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sfd < 0) {
    errHandling("socket");
  }

  struct sockaddr_in serv_addr;
  bzero(&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(opt.ip.c_str());
  serv_addr.sin_port = htons(opt.port);

  if (connect(sfd, reinterpret_cast<struct sockaddr*>(&serv_addr), sizeof(serv_addr)) < 0) {
    errHandling("connect");
  }

  // prepare and send SessionMessage
  SessionMessage session = {htonl(opt.number), htonl(opt.length)};
  int nw = write(sfd, &session, sizeof(SessionMessage));
  assert(nw == sizeof(SessionMessage));

  // prepare PayloadMessage
  int total_len = sizeof(PayloadMessage) + opt.length;
  PayloadMessage* payload = static_cast<PayloadMessage*>(malloc(total_len));
  assert(payload != nullptr);
  payload->length = htonl(opt.length);
  for (int i = 0; i < opt.length; ++i) {
    payload->data[i] = '#';
  }

  // send PayloadMessage
  for (int i = 0; i < opt.number; ++i) {
    nw = write(sfd, payload, total_len);
    assert(nw == total_len);

    uint32_t ack = 0;
    int nr = tcpRead(sfd, &ack, sizeof(int));
    assert(nr == sizeof(int));
    ack = ntohl(ack);

    assert(ack == opt.length);
    printf("%dth: ack=%d\n", i+1, ack);
  }

  free(payload);
  close(sfd);
}

}  // namespace pnp

int main(void) {
  pnp::Options opt;
  pnp::transmit(opt);
  return 0;
}
