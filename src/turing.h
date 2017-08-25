//
// Created by patrick on 13.04.17.
//

#include <memory.h>
#include "doublylinkedlist.h"

#ifndef TURING_TURING_H
#define TURING_TURING_H

typedef struct {
    dl_list * tape;
    dl_node * currentPosition;
    char state;
    char ** table;
    int num_entries;
    int num_steps;
} turing;

turing * turing_new(char **table, int num_entries);

void turing_destroy(turing *self);

void turing_move(turing *self, char direction);

void turing_step(turing *self);

void turing_print_conf(turing *self);

void turing_run(turing *self);

#endif //TURING_TURING_H
