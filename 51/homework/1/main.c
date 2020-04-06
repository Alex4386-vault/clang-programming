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

// length of the stack
int length = 0;

void push(int a);
int pop();
int stack_full();
int stack_empty();

// does 
int main() {

  while (1) {
    // check whether stack is empty.
    if (!stack_empty()) {
      // show elements
      for (LinkNode *wa = head; wa != NULL; wa = wa->nextNode) {
        printf("%d ", wa->data);
      }
    } else {
      // if it's empty, show empty screen
      printf("Stack is empty!");
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
        // check whether stack is full
        if (stack_full()) {
          printf("Stack is full!\n");
          break;
        }

        // push session
        printf("PUSH: ");
        scanf("%d", &input);

        // call push
        push(input);
        break;

      case 2:
        // defensive coding: 
        // check whether stack is empty
        if (stack_empty()) {
          printf("Stack is empty!\n");
          break;
        }

        // call pop and show it to user
        printf("POPPED: %d\n", pop());
        break;

      case 3:
        // show whether stack is full or not
        printf("STACK FULL: ");
        printf(stack_full() ? "true" : "false");
        printf("\n");
        break;

      case 4:
        // show whether stack if empty or not
        printf("STACK EMPTY: ");
        printf(stack_empty() ? "true" : "false");
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


// description: appends data to the stack
// input: data to append (the stack is a global structure)
// returns: void
void push(int a) {
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

// description: removes data from the stack
// input: none
// output: data on top of the stack
int pop() {
  LinkNode *this = head;
  int data;
  
  if (this == NULL) {
    return;
  }

  if (this->nextNode == NULL) {
    data = this->data;
    free(this);
    head = NULL;
  } else {
    while (this->nextNode->nextNode != NULL) {
      this = this->nextNode;
    }
    data = this->nextNode->data;
    free(this->nextNode);
    this->nextNode = NULL;
  }
  
  length--;

  return data;
}

// check whether stack is full
// returns: non-zero when stack is full, otherwise 0.
int stack_full() {
  return length == SIZE;
}

// check whether stack is empty
// returns: non-zero when stack is empty, otherwise 0.
int stack_empty() {
  return length == 0;
}

