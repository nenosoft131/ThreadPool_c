/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   threadpool.h
 * Author: user
 *
 * Created on September 24, 2020, 2:40 AM
 */



#ifndef THREADPOOL_H
#define THREADPOOL_H

#ifdef __cplusplus
extern "C" {
#endif


#define BUFFER_SIZE 1024
#define THREAD_POOL_SIZE 100





    void *connection_handler(int *p_client_soc);
    void *thread_handler(void *arg);
    void thread_init();
    int thread_worker(int new_socket);



#ifdef __cplusplus
}
#endif

#endif /* THREADPOOL_H */

