#include <stdio.h>
#include <stdlib.h>
#include "turing.h"

int main(int argc, char **argv) {
    printf("Initial configuration & Delta:\n");
    int num_entries = argc - 1;
    char** table = argv + 1;
    while(argc--)
        printf("%s\n", *argv++);

    turing * tm = turing_new(table, num_entries);
    turing_run(tm);

    printf("Result: ");
    dl_node * result = tm->currentPosition;
    while(result){
        printf("%c", result->val);
        result = result->next;
    }
    printf("\n");
    printf("Reached in  %i steps.\n", tm->num_steps);

    turing_destroy(tm);

    exit(EXIT_SUCCESS);
}