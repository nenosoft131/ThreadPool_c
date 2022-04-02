/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   queue.c
 * Author: ABYSS
 *
 * Created on September 23, 2020, 11:35 PM
 */

#include "queue.h"
#include <stdlib.h>

node_t *head = NULL;
node_t *tail = NULL;

void enqueue(int *clint_socket) {
    node_t *newnode = malloc(sizeof (node_t));
    newnode->client_socket = clint_socket;
    newnode->next = NULL;
    if (tail == NULL) {
        head = newnode;
    } else {
        tail->next = newnode;
    }
    tail = newnode;
}

int *dequeue() {
    if (head == NULL) {
        return NULL;
    } else {
        int *result = head->client_socket;
        node_t *tmp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        free(tmp);
        return result;
    }
}

