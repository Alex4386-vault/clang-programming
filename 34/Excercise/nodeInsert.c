#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *nextPtr;
} Node;

Node *head;

Node *nodeConstructor(int key) {
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->nextPtr = NULL;
    ptr->key = key;
    return ptr;
}

Node *addNextNode(Node *baseNode, int key) {
    Node *nextPtr = nodeConstructor(key);
    if (baseNode->nextPtr != NULL) {
        nextPtr->nextPtr = baseNode->nextPtr;
    }
    baseNode->nextPtr = nextPtr;
    return nextPtr;
}

void printAllNodes() {
    Node* ptr = head;
    while (ptr != NULL) {
        printf("%d\n", ptr->key);
        ptr = ptr->nextPtr;
    }
}

int main() {
    head = nodeConstructor(100);
    head->nextPtr = nodeConstructor(250);
    head->nextPtr->nextPtr = nodeConstructor(467);

    printAllNodes();

    printf("\n");
    addNextNode(head->nextPtr, 300);

    printAllNodes();

    return 0;
}
