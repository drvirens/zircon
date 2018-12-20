#include "zc_socket_native.h"
#include "zc_log.h"

ZC_PUBLIC int zc_net_socket(int domain, int type, int protocol)
{
  TRACE
  
  return socket(domain, type, protocol);
}
ZC_PUBLIC int zc_net_accept(int fd, struct sockaddr* addr, socklen_t* len)
{
  TRACE
#if defined USE_MOCK_BIND
  return 55;
#else
  return accept(fd, addr, len);
#endif
}
ZC_PUBLIC int zc_net_bind(int fd, const struct sockaddr* addr, socklen_t len)
{
  TRACE
#if defined USE_MOCK_BIND
  return 55;
#else
  return bind(fd, addr, len);
#endif
}
ZC_PUBLIC int zc_net_listen(int fd, int backlog)
{
  TRACE
#if defined USE_MOCK_BIND
  return 55;
#else
  return listen(fd, backlog);
#endif
}