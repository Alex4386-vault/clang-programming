#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *nextPtr;
};

struct Node *getNextNodeAndFree(struct Node *a);

int main() {

    printf("Node Chain\n");
    printf("How many nodes do you want in nodeChain? : ");

    int nodeChainLength;
    scanf("%d", &nodeChainLength);


    struct Node* initNode = (struct Node*) malloc( sizeof(struct Node) );
    struct Node* node = initNode;
    if (initNode == NULL || node == NULL) exit(1);
    for (int i = 0; i < nodeChainLength; i++) {
        scanf("%d", &(node->data));
        struct Node* prevNode = node;
        node = (struct Node*) malloc( sizeof(struct Node) );
        prevNode->nextPtr = node;
    }

    node = initNode;
    if (initNode == NULL || node == NULL) exit(1);
    for (int i = 0; i < nodeChainLength; i++) {
        printf("%d " , node->data);
        struct Node* prevNode = node;
        node = node->nextPtr;
        free(prevNode);
    }

    printf("\n");

}

struct Node *getNextNodeAndFree(struct Node *a) {
    struct Node* b = a->nextPtr;
    free(a);
    printf("Freed!\n");
    return b;
}
