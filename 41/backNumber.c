#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct for storing soccerplayer info
typedef struct SoccerPlayer {
  int backNumber;
  char name[20];
  int age;
  int aMatches;
  int goals;
} SoccerPlayer;

// struct for linked node
typedef struct PlayerNode {
  struct SoccerPlayer soccerPlayer;
  struct PlayerNode *next;
} PlayerNode;

int main() {
  
  // get how many soccer players available for input
  int howMany;
  printf("how many soccer players? : ");
  scanf("%d", &howMany);

  // start of linked list head and nodes
  PlayerNode *playerHead = NULL;
  PlayerNode *currentNode, *prevNode = NULL;

  // read and write to linkedlist
  for (int i = 0; i < howMany; i++) {

    // initialize currentNode
    currentNode = playerHead;

    // tmp variable for storing player data.
    int backNo, age, aMatches, goals;
    char name[21];

    // get player data from user
    printf("%d. \n", i);
    printf("\tBackNo. ");
    scanf("%d", &backNo);
    fflush(stdin);
    printf("\tName. ");
    fgets(name, 21, stdin);
    printf("\tAge. ");
    scanf("%d", &age);
    printf("\tGoals. ");
    scanf("%d", &goals);
    printf("\tA-matches. ");
    scanf("%d", &aMatches);

    // if line return is found, remove it.
    for (int i = 0; i < 21; i++) if (name[i] == '\n') name[i] = 0;

    // allocate heap memory
    PlayerNode *newNode = (PlayerNode *)malloc(sizeof(PlayerNode));

    // exception
    if (newNode == NULL) {
      printf("[ERROR] Memory Allocation Failed\nIs Memory full?\n");
      return 1;
    }

    // save player data to struct.
    newNode->soccerPlayer.backNumber = backNo;
    newNode->soccerPlayer.aMatches = aMatches;
    newNode->soccerPlayer.goals = goals;
    strcpy(newNode->soccerPlayer.name, name);
    newNode->soccerPlayer.age = age;

    // insert by sort
    while (currentNode != NULL) {
      if (currentNode->soccerPlayer.backNumber > newNode->soccerPlayer.backNumber) {
        break;
      }
      prevNode = currentNode;
      currentNode = currentNode->next;
    }
    
    // check whether head is null
    if (prevNode == NULL) {
      // if null, update playerhead to newNode.
      newNode->next = currentNode;
      playerHead = newNode;
    } else {
      // else just add newNode.
      prevNode->next = newNode;
      newNode->next = currentNode;
    }
  }

  printf("\n");

  // get search query
  int minAge;
  int maxAge;
  int minGoals;
  int maxGoals;
  int minAmatches;
  int maxAmatches;

  printf("Minimum Age to Search : ");
  scanf("%d", &minAge);

  printf("Maximum Age to Search : ");
  scanf("%d", &maxAge);
  
  printf("Minimum Goals to Search : ");
  scanf("%d", &minGoals);

  printf("Maximum Goals to Search : ");
  scanf("%d", &maxGoals);

  printf("Minimum A Matches to Search : ");
  scanf("%d", &minAmatches);

  printf("Maximum A Matches to Search : ");
  scanf("%d", &maxAmatches);

  printf("\n");

  // run search
  printf("=========[        %12s        ]=========\n", "Soccer Players");
  printf(" %10s %2s  %19s %3s %4s %4s\n", "Types ", "No", "Name", "Age", "Goal", "AMtch");

  // for all linked List nodes
  for (currentNode = playerHead; currentNode != NULL; currentNode = currentNode->next) {
    SoccerPlayer *player = &currentNode->soccerPlayer;
    // check it matches with the data.
    if (minAge <= player->age && player->age <= maxAge && minGoals <= player->goals && player->goals <= maxGoals && minAmatches <= player->aMatches && player->aMatches <= maxAmatches) {
      printf("%10s: %02d. %19s %3d %4d %5d\n", "Result", player->backNumber, player->name, player->age, player->goals, player->aMatches);

    }
  }

  // free all
  for (currentNode = playerHead; currentNode != NULL;) {
    PlayerNode *tmp = currentNode;
    currentNode = currentNode->next;
    free(tmp);
  }

}
