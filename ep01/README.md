### Layered Network

- Application message
- TCP segment
- IP packet
- Ethernet frame

### Common pitfalls of novices

- Mix business logical with network IO, difficult to unit test.
- Incomplete data received from a TCP peer.
- Incorrectly determine message boundaries when using TCP.
- Sending C struct to peer.
  - Modify the global align setting causes core dump in third party library(ABI broken)
- TCP self connection: localhost:54312 <-> localhost:54321
- Many more in non-blocking network programming

### TCP/IP over 1GB Ehternet

- Ethernet frame

| Part | Bytes | 
| :-----:| :----: 
| Preamble | 8 | 
| MAC | 12 | 
| Type | 2 |
| Payload | 46-1500 |
| CRC | 4 |
| Gap | 12 |
| Total | 84-1538|

- Raw bandwidth
  - 1000M b/s = 125M B/S
- Frame per second
  - Max 125000000 / 84 = 14888000
  - Min 125000000 / 1538 = 81274
- TCP/IP overhead
  - IP header 20B
  - TCP header 20B
  - TCP option 12B(timestamp)
- Max TCP throughput per second
  - 81274 * (1500 - 52) = 117684752B
  - 117M B/S or 112Mi B/S

这道题目要理解，TCP的吞吐到底是什么，本质还是要从分层结构去理解