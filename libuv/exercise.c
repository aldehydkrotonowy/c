#include <stdio.h>
#include <stdlib.h>
#include <uv.h>

int main(void){

    uv_tsp_t server;
    uv_tsp_init(uv_default_loop(), &server);
    struct socaddr_in bind_addr = uv_ip4_addr("0.0.0.0", 6000);

    uv_tcp_bind(&server, bind_addr);
    int r = uv_listen((uv_stream_t*) &server, backlog, on_new_connection);
    if (r){
        fprintf(stderr, "error uv_listener");
        return 1;
    }
    uv_run(uv_devault_loop());
    return 0;
}