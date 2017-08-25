#include <stdio.h>
#include <stdlib.h>
#include "turing.h"

int main(int argc, char **argv) {
    printf("Delta:\n");
    int num_entries = argc - 1;
    char** table = argv + 1;
    while(argc--)
        printf("%s\n", *argv++);

    turing * tm = turing_new(table, num_entries);
    turing_run(tm);

    printf("Result: ");
    dl_node * tape = tm->tape->head;
    while(tape){
        printf("%c", tape->val);
        tape = tape->next;
    }
    printf("\n");
    printf("Reached in  %i steps.\n", tm->num_steps);

    turing_destroy(tm);

    exit(EXIT_SUCCESS);
}