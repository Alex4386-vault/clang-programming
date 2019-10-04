#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* nextNode;
};

struct Node* head = NULL;

struct Node* nodeConstructor(int key) {
    struct Node *nutsh = (struct Node *)malloc(sizeof(struct Node));
    nutsh->nextNode = NULL;
    nutsh->key = key;
    return nutsh;
}


struct Node* findNodeByKey(int key) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        if (key == ptr->key) {
            return ptr;
        }
        ptr = ptr->nextNode;
    }
    return NULL;
}

int getNum() {
    int a;
    scanf("%d", &a);

    return a;
}

int main() {
    struct Node *ptr;
    head = nodeConstructor(100);

    ptr = head;
    ptr->nextNode = nodeConstructor(250);
    ptr->nextNode->nextNode = nodeConstructor(467);

    int a;
    ptr = findNodeByKey(getNum());
    if (ptr == NULL) {
        printf("search key not found\n");
    } else {
        printf("search key found\n");
    }

    return 0;
}
