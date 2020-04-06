#include <stdio.h>
#define SIZE 10

// where data is stored
int stack1[SIZE] = {0,};
int stack2[SIZE] = {0,};

// length of the stack
int length1 = 0;
int length2 = 0;

// description: appends data to the 1st stack
// input: data to append (the stack is a global structure)
// returns: void
void push1(int a) {
  stack1[length1++] = a;
}

// description: removes data from the 1st stack
// input: none
// output: data on top of the stack
int pop1() {
  return stack1[length1--];
}

// description: appends data to the 2nd stack
// input: data to append (the stack is a global structure)
// returns: void
void push2(int a) {
  stack2[length2++] = a;
}

// description: removes data from the 2nd stack
// input: none
// output: data on top of the stack
int pop2() {
  return stack2[length2--];
}

// check whether 1st stack is full
// returns: non-zero when stack is full, otherwise 0.
int stack_full() {
  return length1 == SIZE;
}

// check whether 1st stack is empty
// returns: non-zero when stack is empty, otherwise 0.
int stack_empty() {
  return length1 == 0;
}


int main() {
  while (1) {
    printf("Virtual Queue: \n");

    // check whether stack is empty.
    if (!stack_empty()) {
      // show elements
      for (int i = 0; i < length1; i++) {
        printf("%d ", stack1[i]);
      }
    } else {
      // if it's empty, show empty screen
      printf("Queue is empty!");
    }

    // line return
    printf("\n");

    // selected option
    int option = 0;
    printf("1. enqueue, 2. dequeue, 3. full, 4. empty, 5. exit\n");
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
        printf("ENQUEUE: ");
        scanf("%d", &input);

        push1(input);
        break;

      case 2:
        // defensive coding: 
        // check whether stack is empty
        if (stack_empty()) {
          printf("Stack is empty!\n");
          break;
        }

        while (!stack_empty()) {
          push2(pop1());
        }

        int data = pop2();

        while (length2 != 0) {
          push1(pop2());
        }

        // call pop and show it to user
        printf("DEQUEUED: %d\n", data);
        break;

      case 3:
        // show whether stack is full or not
        printf("QUEUE FULL: ");
        printf(stack_full() ? "true" : "false");
        printf("\n");
        break;

      case 4:
        // show whether stack if empty or not
        printf("QUEUE EMPTY: ");
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

