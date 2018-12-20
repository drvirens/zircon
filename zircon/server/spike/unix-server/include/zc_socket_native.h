#ifndef __zc_socket_native_h__
#define __zc_socket_native_h__

#ifdef __cplusplus
extern "C" {
#endif

#include <fcntl.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include "zc_utils.h"
  
ZC_PUBLIC int zc_net_socket(int domain, int type, int protocol);
ZC_PUBLIC int zc_net_accept(int fd, struct sockaddr* addr, socklen_t* len);
ZC_PUBLIC int zc_net_bind(int fd, const struct sockaddr* addr, socklen_t len);
ZC_PUBLIC int zc_net_listen(int fd, int backlog);

#ifdef __cplusplus
}
#endif

#endif //__zc_socket_native_h__
