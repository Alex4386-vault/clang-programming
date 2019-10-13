#include <stdlib.h>
#include <stdio.h>

struct Node {

    int key;
    struct Node* next;

};

struct Node *head;

struct Node* findPrevNode(struct Node *node) {
    struct Node *ptr = head;
    while (ptr) {
        if (ptr->next == node) { return ptr; }
        ptr = ptr->next;
    }
    return NULL;
}

void deleteNode(struct Node *node) {
    if (node == head) {
        head = node->next;
        free(node);
        return;
    } else {
        findPrevNode(node)->next = node->next;
    }
    return;
}

void printNodes(struct Node* basePtr) {
    struct Node *ptr = basePtr;
    while (ptr != NULL) {
        printf("%d", ptr->key);
        printf(", %p\n", ptr->next);
        ptr = ptr->next;
    }
}

struct Node* insertNode(struct Node* basePtr, int key) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = NULL;
    ptr->key = key;
    ptr->next = basePtr->next;
    basePtr->next = ptr;
    return ptr;
}


int main() {
    head = (struct Node *)malloc(sizeof(struct Node));
    head->key = 100;
    head->next = NULL;
    
    insertNode(head, 250);
    insertNode(head->next, 467);

    printNodes(head);

    deleteNode(head->next);
    printNodes(head);

    return 0;
}