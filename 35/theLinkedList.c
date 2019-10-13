#include <stdlib.h>

struct Node {
    int key;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* constructNode(int key) {
    struct Node* ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->key = key;
    ptr->next = NULL;
    return ptr;
}

void insertNode(struct Node *basePtr, int key) {
    struct Node *ptr = constructNode(key);
    ptr->next = basePtr->next;
    basePtr->next = ptr;
}

struct Node* findNodeByKey(struct Node *baseHead, int key) {
    struct Node* base = baseHead;
    if (base == NULL) {
        base = head;
    }

    while (base) {
        if (base->key == key) {
            return base;
        }
        base = base->next;
    }

    return NULL;
}

struct Node* findPreviousNode(struct Node *baseHead, struct Node* node) {
    struct Node* base = baseHead;

    if (base == NULL) {
        base = head;
    }

    while(base) {
        if (base->next == node) {
            return base;
        }
        base = base->next;
    }

    return NULL;
}

int deleteNode(struct Node* baseHead, struct Node* deleteNode) {
    struct Node *prevNode = findPreviousNode(baseHead, deleteNode);
    if (prevNode == NULL) {
        if (deleteNode == head && baseHead == NULL) {
            head = deleteNode->next;
        }
        if (baseHead != NULL) {
            return -1;
        }
    } else {
        prevNode->next = deleteNode->next;
    }
    free(deleteNode);
    return 0;
}

void swapNode(struct Node* baseHead, struct Node* first, struct Node* second) {
    struct Node* firstPrev = findPreviousNode(baseHead, first);
    struct Node* secondPrev = findPreviousNode(baseHead, first);
    if (first == head) {
        head = second;
    } else {
        firstPrev->next = second;
    }
    if (second == head) {
        head = first;
    }
    struct Node *secondNext = second->next;
    second->next = first;
    secondPrev->next = secondNext;

    return;
}

struct Node* arrayToLinkedList(struct Node *basePtr, int *a, int length) {
    struct Node *ptr = basePtr != NULL ? basePtr : head;
    struct Node *baseNode = ptr;
    for (int i = 0; i < length; i++) {
        if (i == 0 && (head == NULL && basePtr == NULL)) {
            head = constructNode(a[i]);
            ptr = head;
        } else {
            insertNode(ptr, a[i]);
            ptr = ptr->next;
        }
    }
    return 0;
}

void printLinkedLists(struct Node* basePtr) {
    struct Node *ptr = basePtr;
    while (ptr != NULL) {
        printf("%d", ptr->key);
        printf(", %p\n", ptr->next);
        ptr = ptr->next;
    }
}

struct Node* getByIndex(struct Node* basePtr, int index) {
    struct Node *ptr = basePtr;
    for (int i = 0; (i < index && ptr != NULL); i++) {
        ptr = ptr->next;
    }
    return ptr;
}

int main() {
    int a[5] = {10,20,30,40,50};
    arrayToLinkedList(head, a, 5);

    printLinkedLists(head);

    

}

