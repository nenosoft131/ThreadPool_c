/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   threadpool.c
 * Author: ABYSS
 *
 * Created on September 23, 2020, 11:33 PM
 */


#include "threadpool.h"
#include "queue.h"
#include "server.h"
#include <pthread.h>
#include <stdbool.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;
pthread_t thread_pool[THREAD_POOL_SIZE];

/*
 * 
 */

void thread_init() {
    for (int i = 0; i < THREAD_POOL_SIZE; i++) {
        pthread_create(&thread_pool[i], NULL, thread_handler, NULL);
    }

}

int thread_worker(int new_socket) {


    int *clpointer = (int *) malloc(sizeof (int));
    *clpointer = new_socket;
    pthread_mutex_lock(&mutex);
    enqueue(clpointer);
    pthread_cond_signal(&condition_var);
    pthread_mutex_unlock(&mutex);


    return 0;
}

void *connection_handler(int *p_client_soc) {
    int client_soc = *p_client_soc;
    free(p_client_soc);

    char buffer[BUFFER_SIZE];
    size_t bytes_read;


    bytes_read = read(client_soc, buffer, BUFFER_SIZE);

    printf("%s\n", buffer);
    close(client_soc);
    sleep(1);
    // printf("done\n");

    return NULL;
}

void *thread_handler(void *arg) {


    while (true) {

        int *pclinet;
        pthread_mutex_lock(&mutex);

        if ((pclinet = dequeue()) == NULL) {
            pthread_cond_wait(&condition_var, &mutex);
            pclinet = dequeue();
        }
        pthread_mutex_unlock(&mutex);
        if (pclinet != NULL) {
            connection_handler(pclinet);
        }
    }
}

