#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *nextPtr;
} Node;

Node *getNextNode(Node* node) {
    return node->nextPtr;
}

char isThisNodeValid(Node* node) {
    return node != NULL;
}

char isThereNext(Node* node) {
    return node->nextPtr != NULL;
}

Node *initNode() {
    Node *node = (Node *)malloc(sizeof(Node));
    node->nextPtr = NULL;

    return node;
}

void addNextNode(Node *node, int a) {
    Node* nextNode = initNode();
    if (isThereNext(node)) {
        nextNode->nextPtr = node->nextPtr;
        node->nextPtr = nextNode;
    }
    node->nextPtr = nextNode;
    node->nextPtr->data = a;
}

int main() {
    Node* head = initNode();
    head->data = 100;
    addNextNode(head, 250);
    addNextNode(getNextNode(head), 1000);

    addNextNode(head, 175);

    Node* node = head;
    while (1) {
        printf("%d\n", node->data);
        if (isThereNext(node)) {
            node = getNextNode(node);
        } else {
            break;
        }
    }

}
