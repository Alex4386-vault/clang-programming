#include <stdio.h>
#define SIZE 10

// where data is stored
int queue[SIZE] = {0,};

// length of the queue
int front = 0;
int rear = 0;

// description: appends data to the queue
// input: data to append (the queue is a global structure)
// returns: void
void enqueue(int a) {
  queue[rear++] = a;
}

// description: removes data from the queue
// input: none
// output: data on top of the queue
int dequeue() {
  return queue[front++];
}

// check whether queue is full
// returns: non-zero when queue is full, otherwise 0.
int queue_full() {
  return rear == SIZE;
}

// check whether queue is empty
// returns: non-zero when queue is empty, otherwise 0.
int queue_empty() {
  return front == rear;
}

int main() {
  while (1) {
    // check whether queue is empty.
    if (!queue_empty()) {
      // show elements
      for (int i = front; i < rear; i++) {
        printf("%d ", queue[i]);
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
        // check whether queue is full
        if (queue_full()) {
          printf("queue is full!\n");
          break;
        }

        // get user input for data for enqueue
        printf("ENQUEUE: ");
        scanf("%d", &input);

        // call enqueue
        enqueue(input);
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
        // show user whether queue is full
        printf("QUEUE FULL: ");
        printf(queue_full() ? "true" : "false");
        printf("\n");
        break;

      case 4:
        // show user whether queue is empty
        printf("QUEUE EMPTY: ");
        printf(queue_empty() ? "true" : "false");
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

