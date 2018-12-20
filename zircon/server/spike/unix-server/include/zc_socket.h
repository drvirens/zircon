#ifndef __zc_socket_h__
#define __zc_socket_h__

#include "zc_utils.h"

#if defined __cplusplus
extern "C"
{
#endif

    typedef enum tag_enum_socket_error_type
    {
        zc_socket_err_ok,
        zc_socket_err_failed,
        zc_socket_invalid_path
    } zc_socket_error_e;

    typedef enum tag_enum_socket_type
    {
        zc_socket_type_unix,
        zc_socket_type_ip
    } zc_socket_type;

    typedef struct tag_zc_socket zc_socket;

    ZCEXPORT zc_socket *new_instance();
    ZCEXPORT void delete_instance(zc_socket *thiz);

    ZCEXPORT zc_socket_error_e socket_create_unix_socket(zc_socket *thiz, const char *local_path, int *fd);
    ZCEXPORT zc_socket_error_e socket_bind_and_listen(zc_socket *thiz);
    ZCEXPORT zc_socket_error_e socket_connect(zc_socket *thiz);
    ZCEXPORT zc_socket_error_e socket_accept(zc_socket *thiz);

    ZCEXPORT zc_socket_error_e socket_config_enable_nonblocking(zc_socket *thiz, int fd);
    ZCEXPORT zc_socket_error_e socket_config_enable_tcpnodelay(zc_socket *thiz, int fd);
    ZCEXPORT zc_socket_error_e socket_config_enable_keepalive(zc_socket *thiz, int fd);

    ZCEXPORT const char *socket_error_msg(zc_socket *thiz);

#if defined __cplusplus
}
#endif

#endif
