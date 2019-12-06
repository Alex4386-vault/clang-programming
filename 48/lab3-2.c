#include <stdio.h>
#include <stdlib.h>

/* === COMMON === */

// safe memory allocation: 
// exits program when it failed to allocation
void *safeMemoryAllocation(size_t size) {

    // memory allocation
    void *ptr = (void *)malloc(size);
    
    // exception handling
    if (!ptr) { exit(1); }

    return ptr;
}


/* === LINKED LIST === */

// struct definition
typedef struct ListNode {
    // integer key
    int key;

    // next struct pointer
    struct ListNode *nextPtr;
} ListNode;

// constructor for ListNode struct,
// creates listNode with given argument.
// returns: memory allocated listNode
ListNode *listNodeConstructor(int key, ListNode *nextPtr) {
    ListNode *newNode = (ListNode *)safeMemoryAllocation(sizeof(ListNode));
    newNode->key = key;
    newNode->nextPtr = nextPtr;

    return newNode;
}


/* === QUEUE === */

// basePointer: pointer of the beginning of the queue
ListNode *basePointer = NULL;

// queuePointer: pointer of endpoint of the queue
ListNode *queuePointer = NULL;


/* === QUEUE INTERNAL UTILITY FUNCTIONS === */

// finds previous node of given node pointer
ListNode *findPreviousNode(ListNode *ptr) {

    // if there is no queue, return NULL
    if (basePointer == NULL) {
        return NULL;
    }

    // for all, when current Pointer's next is ptr, return
    ListNode *currPtr = basePointer;
    while (currPtr->nextPtr != NULL) {
        if (currPtr->nextPtr == ptr) return currPtr;
        currPtr = currPtr->nextPtr;
    }

    // if none is found, return NULL.
    return NULL;
}

/* === QUEUE INTERNAL FUNCTIONS === */

// insertes new key into queue.
void insert(int n) {

    // if the queue was not started at all
    if (basePointer == NULL) {
        // initialize queue. allocate memory and get pointers.
        basePointer = listNodeConstructor(n, NULL);
        queuePointer = basePointer;
        return;
    }

    // in else, queuePointer should be exist.
    queuePointer->nextPtr = listNodeConstructor(n, NULL);
    queuePointer = queuePointer->nextPtr;
}

// deletes key from queue and returns the key.
int delete(int* n) {
    // if queue was not started at all
    if (basePointer == NULL) {
        // return false
        return 0;
    }

    // set temp pointer as current queue pointer
    ListNode *tmpPointer = basePointer;
    *n = tmpPointer->key;

    // if this is the first node, reset.
    if (basePointer == queuePointer) {
        basePointer = NULL;
        queuePointer = NULL;
    } else {
    // if this is not the first node, make second node to base node.
        basePointer = basePointer->nextPtr;
    }

    // free the deleted struct
    free(tmpPointer);

    // return true
    return 1;
}

// empty the queue
void empty() {
    // until delete is undefined,
    while (basePointer != NULL) {
        // temporary variable
        int a = 0;
        // delete.
        delete(&a);
    }

    return;
}

// print the queue
void print() {

    // temporary variables for printing.
    ListNode *tmpPointer;
    int i;

    /// if queue was not defined, give user a message and return early.
    if (basePointer == NULL) {
        printf("Queue is Empty!!\n");
        return;
    }

    // for basePointer to NULL, print key.
    for (tmpPointer = basePointer, i = 1; tmpPointer != NULL; tmpPointer = tmpPointer->nextPtr, i++) {
        printf("%d. %d\n", i, tmpPointer->key);
    }

    // return
    return;
}

/* === MAIN === */
int main() {

    while (1) {
        // header
        printf("=== QUEUE ===\n");

        // command prompt
        printf("Please Enter Command (1. insert, 2. delete, 3. print, 4. quit) : ");
        
        // select the menu
        int menuSelect = 0;
        scanf("%d", &menuSelect);

        // in case user inputed multiple variables at once,
        // flush stdin.
        fflush(stdin);

        // temporary var to save user input.
        int tmp;

        // for each menu select.
        switch(menuSelect) {
            case 1:
                // make user enter the key
                printf("Please enter the key you want to insert : ");
                scanf("%d", &tmp);

                // just insert it
                insert(tmp);
                break;
            case 2:
                // delete and save to tmp.
                if (delete(&tmp)) {
                    printf("deleted %d\n", tmp);
                } else {
                    printf("deleting failed!\n");
                }
                break;
            case 3:
                // print the queue
                print();
                break;
            case 4:
                // terminate program
                printf("Bye!\n");
                exit(0);
                break;
            default:
                // invalid command
                printf("Invalid Command...\n");
                break;
        }
        // in case user inputted multiple variables at once,
        // flush stdin.
        fflush(stdin);


        printf("\n");
    }

    return 0;
}
