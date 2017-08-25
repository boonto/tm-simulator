//
// Created by patrick on 13.04.17.
//

#include <stdlib.h>
#include "doublylinkedlist.h"

dl_node *dl_node_new(int val) {
    dl_node *self = malloc(sizeof(dl_node));

    self->val = val;
    self->next = NULL;
    self->prev = NULL;

    return self;
}

dl_list *dl_list_new() {
    dl_list *self = malloc(sizeof(dl_list));

    self->head = NULL;
    self->tail = NULL;
    self->length = 0;

    return self;
}

void dl_list_destroy(dl_list *self) {
    unsigned int len = self->length;
    dl_node *next;
    dl_node *current = self->head;

    while(len--) {
        next = current->next;
        free(current);
        current = next;
    }

    free(self);
}

dl_node *dl_list_rpush(dl_list *self, dl_node *node) {
    if(!node) return NULL;

    if(self->length) {
        node->prev = self->tail;
        node->next = NULL;
        self->tail->next = node;
        self->tail = node;
    } else {
        self->head = self->tail = node;
        node->prev = node->next = NULL;
    }

    ++self->length;
    return node;
}

dl_node *dl_list_lpush(dl_list *self, dl_node *node) {
    if(!node) return NULL;

    if(self->length) {
        node->next = self->head;
        node->prev = NULL;
        self->head->prev = node;
        self->head = node;
    } else {
        self->head = self->tail = node;
        node->prev = node->next = NULL;
    }

    ++self->length;
    return node;
}

dl_node *dl_list_rpop(dl_list *self) {
    if(!self->length) return NULL;

    dl_node *node = self->tail;

    if(--self->length) {
        self->tail = node->prev;
        self->tail->next = NULL;
    } else {
        self->tail = self->head = NULL;
    }

    node->next = node->prev = NULL;
    return node;
}

dl_node *dl_list_lpop(dl_list *self) {
    if(!self->length) return NULL;

    dl_node *node = self->head;

    if(--self->length) {
        self->head = node->next;
        self->head->prev = NULL;
    } else {
        self->head = self->tail = NULL;
    }

    node->next = node->prev = NULL;
    return node;
}

dl_node *dl_list_at(dl_list *self, unsigned int index) {
    if(index >= self->length) return NULL;

    dl_node *current = self->head;

    while(index--) {
        current = current->next;
    }

    return current;
}
