/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   queue.h
 * Author: ABYSS
 *
 * Created on September 23, 2020, 11:35 PM
 */

#ifndef QUEUE_H
#define QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

    struct node {
        struct node *next;
        int *client_socket;
    };
    typedef struct node node_t;

    void enqueue(int *clint_socket);
    int *dequeue();



#ifdef __cplusplus
}
#endif


#endif /* QUEUE_H */

