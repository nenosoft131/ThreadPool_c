/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   server.h
 * Author: user
 *
 * Created on September 24, 2020, 2:47 AM
 */

#ifndef SERVER_H
#define SERVER_H

#ifdef __cplusplus
extern "C" {
#endif


#define SERVERPORT 8080
#define SERVERBLOG 10000
#define SOCKETERROR (-1)

#define SOCKET_CREATION_ERROR "Error in Socket Creation"
#define SOCKET_BIND_ERROR "Error in Socket Bind"
#define SOCKET_LISTEN_ERROR "Listen Failed"
#define SOCKET_OPT_ERROR "Socket OPT Failed"

    typedef struct sockaddr_in SA_IN;
    typedef struct sockaddr SA;


    int server_init();
    int inspect(int exp, const char *data);


#ifdef __cplusplus
}
#endif

#endif /* SERVER_H */

