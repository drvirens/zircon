#include "zc_socket_native.h"
#include "zc_log.h"

ZC_PUBLIC int NET_socket(int domain, int type, int protocol)
{
  TRACE
  
  return socket(domain, type, protocol);
}
ZC_PUBLIC int NET_accept(int fd, struct sockaddr* addr, socklen_t* len)
{
  TRACE
return accept(fd, addr, len);
#if defined USE_MOCK_BIND
  return 0;
#else
  return accept(fd, addr, len);
#endif
}
ZC_PUBLIC int NET_bind(int fd, const struct sockaddr* addr, socklen_t len)
{
  TRACE
return bind(fd, addr, len);
}
ZC_PUBLIC int NET_listen(int fd, int backlog)
{
  TRACE
  return listen(fd, backlog);
}
ZC_PUBLIC int NET_close(int fd) {
  TRACE
  return close(fd);
}
