//
// Created by patrick on 13.04.17.
//

#ifndef TURING_DOUBLYLINKEDLIST_H
#define TURING_DOUBLYLINKEDLIST_H

#include <stdio.h>

typedef struct dl_node {
    struct dl_node *prev;
    struct dl_node *next;
    char val;
} dl_node;

typedef struct {
    dl_node *head;
    dl_node *tail;
    unsigned int length;
} dl_list;

dl_node * dl_node_new(int val);

dl_list * dl_list_new();

void dl_list_destroy(dl_list *self);

dl_node * dl_list_rpush(dl_list *self, dl_node *node);

dl_node * dl_list_lpush(dl_list *self, dl_node *node);

dl_node * dl_list_rpop(dl_list *self);

dl_node * dl_list_lpop(dl_list *self);

dl_node * dl_list_at(dl_list *self, unsigned int index);

#endif //TURING_DOUBLYLINKEDLIST_H
