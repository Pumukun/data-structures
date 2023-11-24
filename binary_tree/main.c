#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "binary_tree.h"

int main() {
    Binary_Tree* tree = new_tree(NULL);
    srand(time(NULL));

    /*
    for (int i = 0; i < 10; ++i) {
        int* new = (int*)malloc(sizeof(int));
        *new = rand() / 1000000;
        push_node(tree, new, INT);
    }
    */

    int n1 = 3;
    push_node(tree, &n1, INT);

    int n2 = 9;
    push_node(tree, &n2, INT);

    int n3 = 2;
    push_node(tree, &n3, INT);

    int n4 = -2;
    push_node(tree, &n4, INT);

    int n5 = 7;
    push_node(tree, &n5, INT);


    show_tree(tree, INT);
    printf("size: %u\n", (unsigned)tree->size);

    remove_node(tree, &n3, INT);

    show_tree(tree, INT);
    printf("size: %u\n", (unsigned)tree->size);


    return 0;
}
