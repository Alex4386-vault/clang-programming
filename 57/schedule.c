#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PseudoProcessControlBlockLinkedList {
  struct PseudoProcessControlBlock *payload;
  struct PseudoProcessControlBlockLinkedList *nextNode;
};

struct PseudoProcessControlBlock {
  int pid;
  int startTick;
  int runtimeTick;
  int processed;
};

struct PseudoProcessResultLinkedList {
  struct PseudoProcessResultBlock *payload;
  struct PseudoProcessResultLinkedList *nextNode;
};

struct PseudoProcessResultBlock {
  int pid;
  int processStartTick;
  int processFinishTick;
  int turnaroundTick;
  int waitingTick;
  int responseTick;
};

enum ProcessSchedulingMethod {
  FCFS = 1,
  SJF = 2,
  SRTF = 3
};

struct PseudoProcessControlBlockLinkedList *pcbList = NULL;
struct PseudoProcessResultLinkedList *resList = NULL;
enum ProcessSchedulingMethod pMethod = 0;

void read_proc_list(const char* file_name) {
  FILE *fileHandle = fopen(file_name, "r");
  if (fileHandle == NULL) {
    printf("[error] Reading file %s failed!\n", file_name);
    exit(1);
  }

  int processCount = 0;
  fscanf(fileHandle, "%d", &processCount);
  
  for (int i = 0; i < processCount; i++) {

    struct PseudoProcessControlBlock *tmpPCB = 
      (struct PseudoProcessControlBlock *)malloc(sizeof(
        struct PseudoProcessControlBlock
      ));

    int *pcbPid = &(tmpPCB->pid);
    int *pcbStartTick = &(tmpPCB->startTick);
    int *pcbRuntimeTick = &(tmpPCB->runtimeTick);
    tmpPCB->processed = 0;

    fscanf(fileHandle, "%d %d %d", pcbPid, pcbStartTick, pcbRuntimeTick);

    struct PseudoProcessControlBlockLinkedList *tmpNode = 
      (struct PseudoProcessControlBlockLinkedList *)malloc(sizeof(
        struct PseudoProcessControlBlockLinkedList
      ));

    tmpNode->nextNode = NULL;
    tmpNode->payload = tmpPCB;
    
    if (pcbList == NULL) {
      pcbList = tmpNode;
    } else {
      struct PseudoProcessControlBlockLinkedList *tmptmpNode = pcbList;
      while (tmptmpNode->nextNode != NULL) {
        tmptmpNode = tmptmpNode->nextNode;
      }

      tmptmpNode->nextNode = tmpNode;
    }
  }
}

void set_schedule(int method) {
  if (1 <= method && method <= 3) {
    pMethod = (enum ProcessSchedulingMethod)method;
  } else {
    printf("[error] Invalid Schedule Method!");
    exit(1);
  }
}

void deep_copy_schedule(struct PseudoProcessControlBlockLinkedList *a, struct PseudoProcessControlBlockLinkedList **b) {
  if (a == NULL) return;
  *b = (struct PseudoProcessControlBlockLinkedList *)malloc(sizeof(struct PseudoProcessControlBlockLinkedList));
  (*b)->payload = (struct PseudoProcessControlBlock *)malloc(sizeof(struct PseudoProcessControlBlock));

  memcpy(*b, a, sizeof(struct PseudoProcessControlBlockLinkedList));
  memcpy((*b)->payload, a->payload, sizeof(struct PseudoProcessControlBlock));
  return deep_copy_schedule(a->nextNode, &((*b)->nextNode));
}

int do_schedule(int tick) {
  struct PseudoProcessControlBlockLinkedList *copiedSchedule;
  deep_copy_schedule(pcbList, &copiedSchedule);

  int prevId = -1;
  int currentTick = 0;

  int pid = -1;

  switch (pMethod) {
    case FCFS:
      for (currentTick = 0; currentTick <= tick; currentTick++) {
        for (struct PseudoProcessControlBlockLinkedList *list = copiedSchedule; list != NULL; list = list->nextNode) {
          struct PseudoProcessControlBlock *block = list->payload;

          if (currentTick >= block->startTick) {
            if (block->processed) { continue; }

            if (currentTick <= tick && tick < currentTick + block->runtimeTick) {
              struct PseudoProcessResultBlock *res = (struct PseudoProcessResultBlock *)malloc(sizeof(PseudoProcessResultBlock));
              return block->pid;
            }

            for (int i = 0; i < block->runtimeTick; i++) {
              currentTick++;
            }
          }
        }
      }
      break;

    case SJF:
      if (1) {
        int mostLessTick = 0x7FFFFFFF;
        struct PseudoProcessControlBlock *processBlock = NULL;

        for (struct PseudoProcessControlBlockLinkedList *wa = copiedSchedule;
              wa != NULL; wa = wa->nextNode) {
          
          wa->payload->processed = 0;
          if (wa->payload->startTick > tick) {
            wa->payload->processed = 1;
          }
        }

        int shuffleCount = 0;
        for (int j = 0; j <= shuffleCount; j++) {
          for (struct PseudoProcessControlBlockLinkedList *wa = copiedSchedule;
              wa != NULL; wa = wa->nextNode) {
            
            if (wa->nextNode == NULL) { break; }

            if (wa->payload->runtimeTick > wa->nextNode->payload->runtimeTick) {
              struct PseudoProcessControlBlock *pcb = wa->payload;
              wa->payload = wa->nextNode->payload;
              wa->nextNode->payload = pcb;
            }

            if (j == 0) shuffleCount++;
          }
        }
        
        int base = 0;
        for (struct PseudoProcessControlBlockLinkedList *wa = copiedSchedule;
            wa != NULL; wa = wa->nextNode) {
          
          if (!wa->payload->processed) {
            if (base <= tick && tick <= base + wa->payload->runtimeTick) {
              return wa->payload->pid;
            }
          }
        }
        return 0;

      }
      break;

    case SRTF:

      for (currentTick = 0; currentTick <= tick; currentTick++) {
        struct PseudoProcessControlBlock *processBlock = NULL;
        int mostLessTick = 0x7FFFFFFF;

        for (struct PseudoProcessControlBlockLinkedList *list = copiedSchedule; list != NULL; list = list->nextNode) {
          struct PseudoProcessControlBlock *block = list->payload;

          if (currentTick >= block->startTick) {
            if (!block->processed) {
              if (block->runtimeTick < mostLessTick) {
                printf("Most less tick: %d\n", block->runtimeTick);
                processBlock = block;
                mostLessTick = block->runtimeTick;
              }
            }
          }
        }

        if (processBlock) {
          processBlock->runtimeTick--;
          pid = processBlock->pid;

          if (processBlock->runtimeTick <= 0) {
            processBlock->processed = 1;
          }
        } else {
          pid = 0;
        }
      }
      return pid;
      break;
    default:
      return 0;
  }
  return -1;
}

struct PseudoProcessControlBlock *find_pcb(struct PseudoProcessControlBlockLinkedList *schedule, int pid) {
  struct PseudoProcessControlBlockLinkedList *tmpNode = schedule;
  while (tmpNode->nextNode != NULL) {
    if (tmpNode->payload->pid == pid) {
      return tmpNode->payload;
    }
  }
  return NULL;
}

void print_performance() {

}
