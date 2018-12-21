#ifndef __zc_socket_h__
#define __zc_socket_h__

#include "zc_utils.h"
#include "zc_socket_native.h"

#if defined __cplusplus
extern "C" {
#endif

typedef enum tag_enum_socket_error_type {
  zc_socket_err_ok,
  zc_socket_err_failed,
  zc_socket_invalid_path
} zc_socket_error_e;

typedef enum tag_enum_socket_type {
  zc_socket_type_unix,
  zc_socket_type_ip
} zc_socket_type;

typedef struct tag_zc_socket zc_socket_t;

ZC_PUBLIC zc_socket_t* new_zc_socket(zc_socket_type type);
ZC_PUBLIC void delete_instance(zc_socket_t* thiz);

ZC_PUBLIC zc_socket_error_e socket_create_unix_socket(zc_socket_t* thiz, const char* local_path, int* fd);
ZC_PUBLIC zc_socket_error_e socket_bind_and_listen(zc_socket_t* thiz, int fd, struct sockaddr_un* sa, int backlog);
ZC_PUBLIC zc_socket_error_e socket_connect(zc_socket_t* thiz, int fd);
ZC_PUBLIC zc_socket_error_e socket_accept(zc_socket_t* thiz, int fd);

ZC_PUBLIC zc_socket_error_e socket_set_nonblocking(zc_socket_t* thiz, int fd);
ZC_PUBLIC zc_socket_error_e socket_set_tcpnodelay(zc_socket_t* thiz, int fd);
ZC_PUBLIC zc_socket_error_e socket_set_keepalive(zc_socket_t* thiz, int fd);
ZC_PUBLIC zc_socket_error_e
socket_set_reuseportaddress(zc_socket_t* thiz, int fd);

ZC_PUBLIC const char* socket_error_msg(zc_socket_t* thiz);

#if defined __cplusplus
}
#endif

#endif
