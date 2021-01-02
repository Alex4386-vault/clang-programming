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
LinkNode *head2 = NULL;

// length of the stack
int length = 0;

int length2 = 0;


void push(int a);
void push2(int a);
int pop();
int pop2();
int stack_full();
int stack_empty();
int stack2_empty();
int recurse_binary(int a);

int main() {
  int data = 0;

  // selected option
  printf("Input Number: ");
  scanf("%d", &data);

  recurse_binary(data);
  
  while (!stack_empty()) {
    int a = pop();
    printf("%d", a);
  }

  printf("\n");

  return 0;
}

int recurse_binary(int a) {
  push(a % 2);
  if (a < 2) { return 0; }
  recurse_binary(a / 2);

  return 0;
}


// description: appends data to the stack
// input: data to append (the stack is a global structure)
// returns: void
void push(int a) {
  LinkNode *new = (LinkNode *)malloc(sizeof(LinkNode));

  // defensive coding: if memory allocation failed
  if (new == NULL) {
    printf("mem alloc failed!");
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

void push2(int a) {
  LinkNode *new = (LinkNode *)malloc(sizeof(LinkNode));

  // defensive coding: if memory allocation failed
  if (new == NULL) {
    printf("mem alloc failed!");

    return;
  }

  new->data = a;
  new->nextNode = NULL;

  if (head2 != NULL) {
    LinkNode *this = head2;
    while (this->nextNode != NULL) {
      this = this->nextNode;
    }
    this->nextNode = new;
  } else {
    head2 = new;
  }

  length2++;
}

// description: removes data from the stack
// input: none
// output: data on top of the stack
int pop() {
  LinkNode *this = head;
  int data;
  
  if (this == NULL) {
    return 0;
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

int pop2() {
  LinkNode *this = head2;
  int data;
  
  if (this == NULL) {
    return 0;
  }

  if (this->nextNode == NULL) {
    data = this->data;
    free(this);
    head2 = NULL;
  } else {
    while (this->nextNode->nextNode != NULL) {
      this = this->nextNode;
    }
    data = this->nextNode->data;
    free(this->nextNode);
    this->nextNode = NULL;
  }
  
  length2--;

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

// check whether stack is empty
// returns: non-zero when stack is empty, otherwise 0.
int stack2_empty() {
  return length2 == 0;
}


