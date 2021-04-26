### Basic, non-concurrent examples
- TTCP: classic TCP performance testing tool.
- Round-trip: measure clock error between two hosts.
- Netcat: a Swiss knife
- Slow sink/source

### Concurrent examples
- SOCKS proxy server
  - Relay two TCP connections
- Soduku server
  - A lot services fit in this request-response model
- Simple memcached
- Broadcasting to multiple TCP connections
  - How to deal with slow receiver

### Data processing with multiple machines
- Parallel N-Queens
- Median of numbers across machines
- Frequent queries
- Distributed sorting

### Advanced topics
- RPC-A basic building block for various servers
- Load balancing
  - Better than round-robin
- Capacity of a serving system
  - How many machines do I need to support X QPS?
  - What will be the number of replicas of each component.
- Fight for (tail)latency
  - Mean and percenties:95%,99%