#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int key;
    struct NODE *next;
};

struct NODE *node;

int main() {
    node = (struct NODE *) malloc( sizeof(struct NODE) );

    node->key = 10;
    node->next = NULL;

    free(node);
}
