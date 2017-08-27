//
// Created by patrick on 13.04.17.
//

#include <stdlib.h>
#include "turing.h"

void turing_run(turing *self) {
    while(self->state != 'A') {
        turing_print_conf(self);

        turing_step(self);
    }
    turing_print_conf(self);
}

void turing_print_conf(turing *self) {
    printf("Step %i:", self->num_steps);
    dl_node * node = self->tape->head;
    while(node != self->currentPosition) {
        printf("%c", node->val);
        node = node->next;
    }
    printf("|%c|", self->state);
    while(node) {
        printf("%c", node->val);
        node = node->next;
    }
    printf("\n");
}

void turing_step(turing *self) {
    int i = self->num_entries;
    char **table = self->table;
    self->num_steps++;

    while (i--) {
        if(((*table)[0] == self->state) && ((*table)[2] == self->currentPosition->val)) {
            self->state = (*table)[4];
            self->currentPosition->val = (*table)[6];
            turing_move(self, (*table)[8]);
            break;
        }
        table++;
    }
}

turing *turing_new(char **table, int num_entries) {
    turing * tm = malloc(sizeof(turing));
    tm->state = **table;
    tm->tape = dl_list_new();
    table++;
    while (strlen(*table) > 0) {
        dl_node* node;
        if (**table == '^') {
            if (strlen(*table) <= 1) {
                node = dl_node_new('#');
            } else {
                (*table)++;
                node = dl_node_new(**table);
            }
            tm->currentPosition = node;
        } else {
            node = dl_node_new(**table);
        }
        dl_list_rpush(tm->tape, node);
        (*table)++;
    }
    table++;
    tm->table = table;
    tm->num_entries = num_entries - 2;
    tm->num_steps = 0;
    return tm;
}

void turing_move(turing *self, char direction) {
    if (direction == '<') {
        if(self->currentPosition->prev) {
            self->currentPosition = self->currentPosition->prev;
        } else {
            dl_node * empty = dl_node_new('#');
            dl_list_lpush(self->tape, empty);
            self->currentPosition = self->currentPosition->prev;
        }
    } else if (direction == '>') {
        if(self->currentPosition->next) {
            self->currentPosition = self->currentPosition->next;
        } else {
            dl_node * empty = dl_node_new('#');
            dl_list_rpush(self->tape, empty);
            self->currentPosition = self->currentPosition->next;
        }
    } else if (direction == '.') {
        //do nothing
    }
}

void turing_destroy(turing *self) {
    dl_list_destroy(self->tape);
    self->state = 0;
    self->currentPosition = NULL;
    self->table = NULL;
    free(self);
}
