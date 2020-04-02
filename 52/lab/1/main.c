#include <stdio.h>
#define SIZE 5

int queue[SIZE] = {0,};

int front = -1;
int rear = -1;

int insert(int a);
void force_insert(int a);
int delete();

int main() {
  while(1) {
    int option = 0;

    printf("Circular Buffer: \n");

    for (int i = front; i < rear; i = (i + 1) % SIZE) {
      printf("%d ", queue[i]);
    }
    printf("\n");
    printf("Front @ %d, Rear @ %d\n", front, rear);

    printf("1. insert (overwrite), 2. insert (overflow), 3. delete, 4. exit\n");

    scanf("%d", &option);
    int value = 0;  

    switch (option) {
      case 1:
        printf("Insert (overwrite): ");
        scanf("%d", &value);

        force_insert(value);
        printf("Inserted: %d\n", value);
        break;

      case 2:
        printf("Insert (overflow): ");
        scanf("%d", &value);

        if (!insert(value)) {
          printf("Buffer Overflow Detected! Not Inserting!\n");
        }

        break;

      case 3:
        printf("Deleting...\n");
        printf("Deleted: %d\n", delete());

      case 4:
        printf("Terminating...\n");
        break;

      default:
        printf("Invalid Command.\n");
        break;
    }

    if (option == 4) {
      break;
    }

    printf("\n");

  }
}

int insert(int a) {
  if ((rear + 1) % SIZE == front) {
    return 0;
  }
  force_insert(a);
  return 1;
}

void force_insert(int a) {
  if (front == -1) front = 0;
  if (rear == -1) rear = 0;

  queue[rear] = a;
  rear = (rear + 1) % SIZE;
}

int delete() {
  int data = queue[front];
  front = (front + 1) % SIZE;
  return data;
}

