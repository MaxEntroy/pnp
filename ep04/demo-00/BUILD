cc_library(
  name = "common",
  srcs = [
    "common.cc",
  ]
)

cc_binary(
  name = "ttcp_cli",
  srcs = [
    "ttcp_client.cc"
  ],
  deps = [
    ":common"
  ]
)

cc_binary(
  name = "ttcp_serv",
  srcs = [
    "ttcp_server.cc"
  ],
  deps = [
    ":common"
  ]
)
