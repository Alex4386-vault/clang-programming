#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct LinkNode {
  int data;
  struct LinkNode *nextNode;
};

typedef struct LinkNode LinkNode;

// head of the Linked List
LinkNode *head = NULL;
int length = 0;

void enqueue(int a);
int dequeue();
int queue_full();
int queue_empty();

int main() {
  while (1) {
    // check whether queue is empty.
    if (!queue_empty()) {
      // show elements
      for (LinkNode *wa = head; wa != NULL; wa = wa->nextNode) {
        printf("%d ", wa->data);
      }
    } else {
      // if it's empty, show empty screen
      printf("queue is empty!");
    }

    // line return
    printf("\n");

    // selected option
    int option = 0;
    printf("1. push, 2. pop, 3. full, 4. empty, 5. exit\n");
    printf("Select an option: ");
    scanf("%d", &option);

    // variable for storing input
    int input = 0;
    switch(option) {
      case 1:
        // defensive coding: 
        // check whether queue is full
        if (queue_full()) {
          printf("queue is full!\n");
          break;
        }

        // enqueued
        printf("ENQUEUED: ");
        scanf("%d", &input);

        // call push
        push(input);
        break;

      case 2:
        // defensive coding: 
        // check whether queue is empty
        if (queue_empty()) {
          printf("queue is empty!\n");
          break;
        }

        // call dequeue and show it to user
        printf("DEQUEUED: %d\n", dequeue());
        break;

      case 3:
        // show whether queue is full or not
        printf("QUEUE FULL: ");
        printf(queue_full() ? "true" : "false");
        printf("\n");
        break;

      case 4:
        // show whether queue if empty or not
        printf("QUEUE EMPTY: ");
        printf(queue_empty() ? "true" : "false");
        printf("\n");
        break;
      
      case 5:
        // terminate
        printf("Terminating Session... ");
        break;
      
      default:
        // invalid command
        printf("invalid command!\n");
        break;
    }

    // line return
    printf("\n");

    // exit the loop if option is 5
    if (option == 5) {
      break;
    }
  }

  return 0;
}



// description: appends data to the queue
// input: data to append (the queue is a global structure)
// returns: void
void enqueue(int a) {
  LinkNode *new = (LinkNode *)malloc(sizeof(LinkNode));

  // defensive coding: if memory allocation failed
  if (new == NULL) {
    return;
  }

  new->data = a;
  new->nextNode = NULL;

  if (head != NULL) {
    LinkNode *this = head;
    while (this->nextNode != NULL) {
      this = this->nextNode;
    }
    this->nextNode = new;
  } else {
    head = new;
  }
  
  length++;
}

// description: removes data from the queue
// input: none
// output: data on top of the queue
int dequeue() {
  LinkNode *this = head;
  int data;

  data = head->data;

  head = head->nextNode;

  free(head);
  length--;
  return data;
}

// check whether queue is full
// returns: non-zero when queue is full, otherwise 0.
int queue_full() {
  return length == SIZE;
}

// check whether queue is empty
// returns: non-zero when queue is empty, otherwise 0.
int queue_empty() {
  return length == 0;
}



