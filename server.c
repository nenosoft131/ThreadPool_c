/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   server.c
 * Author: ABYSS
 *
 * Created on September 23, 2020, 11:33 PM
 */

#include "server.h"
#include "threadpool.h"

#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int server_init() {

    int server_soc, opt = 1, addr_size, client_soc;
    SA_IN server_addr, client_addr;
    thread_init();
    inspect(server_soc = socket(AF_INET, SOCK_STREAM, 0), SOCKET_CREATION_ERROR);
    inspect(setsockopt(server_soc, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
            &opt, sizeof (opt)), SOCKET_OPT_ERROR);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVERPORT);

    inspect(bind(server_soc, (SA *) & server_addr, sizeof (server_addr)), SOCKET_BIND_ERROR);
    inspect(listen(server_soc, SERVERBLOG), SOCKET_LISTEN_ERROR);

    printf("SERVER is Running\n");
    while (true) {

        addr_size = sizeof (SA_IN);
        inspect(client_soc = accept(server_soc, (SA *) & client_addr, (socklen_t *) & addr_size), "ERROR");
        thread_worker(client_soc);
    }

    return 0;
}

int inspect(int exp, const char *data) {
    if (exp == SOCKETERROR) {
        perror(data);
        //exit(1);
    }
    return exp;
}

