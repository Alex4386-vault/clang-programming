#include <stdio.h>
#define SIZE 10

// where data is stored
int queue1[SIZE] = {0,};
int queue2[SIZE] = {0,};

// length of the queue
int front1 = 0;
int rear1 = 0;
int front2 = 0;
int rear2 = 0;

// description: appends data to the 1st queue
// input: data to append (the queue is a global structure)
// returns: void
void enqueue1(int a) {
  queue1[rear1++] = a;
}

// description: removes data from the 1st queue
// input: none
// output: data on top of the queue
int dequeue1() {
  return queue1[front1++];
}

// description: appends data to the 2nd queue
// input: data to append (the queue is a global structure)
// returns: void
void enqueue2(int a) {
  queue2[rear2++] = a;
}

// description: removes data from the 2nd queue
// input: none
// output: data on top of the queue
int dequeue2() {
  return queue2[front2++];
}

// check whether queue is full
// returns: non-zero when queue is full, otherwise 0.
int queue1_full() {
  return rear1 == SIZE;
}

// check whether queue is empty
// returns: non-zero when queue is empty, otherwise 0.
int queue1_empty() {
  return front1 == rear1;
}

int main() {
  while (1) {
    printf("Virtual Stack:\n");

    // check whether queue is empty.
    if (!queue1_empty()) {
      // show elements
      for (int i = front1; i < rear1; i++) {
        printf("%d ", queue1[i]);
      }
    } else {
      // if it's empty, show empty screen
      printf("Virtual Stack is empty!");
    }
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
        if (queue1_full()) {
          printf("queue is full!\n");
          break;
        }

        // get user input for data for enqueue
        printf("PUSH: ");
        scanf("%d", &input);

        // call enqueue
        enqueue1(input);
        break;

      case 2:
        // defensive coding: 
        // check whether queue is empty
        if (queue1_empty()) {
          printf("queue is empty!\n");
          break;
        }

        while (front1 != rear1 - 1) {
          enqueue2(dequeue1());
        }
        int data = dequeue1();
        
        while (front2 != rear2) {
          enqueue1(dequeue2());
        }
        
        // call dequeue and show it to user
        printf("DEQUEUED: %d\n", data);
        break;

      case 3:
        // show user whether queue is full
        printf("QUEUE FULL: ");
        printf(queue1_full() ? "true" : "false");
        printf("\n");
        break;

      case 4:
        // show user whether queue is empty
        printf("QUEUE EMPTY: ");
        printf(queue1_empty() ? "true" : "false");
        printf("\n");
        break;
      
      case 5:
        // termination
        printf("Terminating Session... ");
        break;
      
      default:
        printf("invalid command!");
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

