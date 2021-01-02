#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_BUCKETS 33
#define ORIGIN_STR_MAX_LENGTH 255
#define OVERFLOW_BUCKET 6

char hash_bucket[HASH_BUCKETS][OVERFLOW_BUCKET][ORIGIN_STR_MAX_LENGTH] = { { { 0, }, }, };

int str_hash(char *str);
int insert_str(char *str);
int search_str(char *str);
int safe_insert_str(char *str);
int delete_str(char *str);
void show_hashtable();

int main() {
  char *fileName = "keyinput.txt";
  FILE *fp = fopen(fileName, "r");

  while (!feof(fp)) {
    char str[ORIGIN_STR_MAX_LENGTH] = { 0, };

    fscanf(fp, "%s", str);
    insert_str(str);
  }

  printf("== HASH TABLE ==\n");
  show_hashtable();

  printf("\n");
  printf("== SEARCH ==\n");
  printf("%s\n", (search_str("Blue") ? "found" : "not found"));
  printf("%s\n", (search_str("black") ? "found" : "not found"));
  printf("%s\n", (search_str("purple") ? "found" : "not found"));


  printf("\n");
  printf("== DELETE ==\n");
  printf("%s\n", (delete_str("Purple") ? "deleted" : "not found"));
  printf("%s\n", (delete_str("Blue") ? "deleted" : "not found"));
  printf("%s\n", (delete_str("Green") ? "deleted" : "not found"));


  printf("\n");
  printf("== INSERT ==\n");
  printf("%s\n", (insert_str("Green") ? "inserted" : "exists"));
  printf("%s\n", (insert_str("White") ? "inserted" : "exists"));
  printf("%s\n", (insert_str("Golden") ? "inserted" : "exists"));
  printf("%s\n", (insert_str("nedloG") ? "inserted" : "exists"));


  printf("\n");
  printf("== SEARCH ==\n");
  printf("%s\n", (search_str("Blue") ? "found" : "not found"));
  printf("%s\n", (search_str("nedloG") ? "found" : "not found"));
  printf("%s\n", (search_str("Yellow") ? "found" : "not found"));
  printf("%s\n", (search_str("Green") ? "found" : "not found"));

  printf("\n");
  printf("== HASH TABLE ==\n");
  show_hashtable();

  return 0;
}


int str_hash(char *str) {
  int sum = 0;
  for (char *i = str; *i != 0; i++) {
    sum += *i;
  }
  return sum % HASH_BUCKETS;
}

int insert_str(char *str) {
  int hash = str_hash(str);
    
  int check = 0;
  for (int i = 0; i < OVERFLOW_BUCKET; i++) {
    if (hash_bucket[hash][i][0] == 0) {
      strcpy(hash_bucket[hash][i], str);
      return 1;
    }
  }
  return 0;
}

int search_str(char *str) {
  int hash = str_hash(str);

  for (int i = 0; i < OVERFLOW_BUCKET; i++) {
    char *wStr = hash_bucket[hash][i];

    if (!strcmp(str, wStr)) return 1;
  }

  return 0;
}

int safe_insert_str(char *str) {
  if (search_str(str)) {return 0;}
  
  insert_str(str);
  return 1;
}

int delete_str(char *str) {
  int hash = str_hash(str);
  int lastIndex = OVERFLOW_BUCKET - 1;

  for (lastIndex = OVERFLOW_BUCKET - 1; lastIndex >= 0 && hash_bucket[hash][lastIndex][0] != 0; lastIndex--) {}
  if (lastIndex == 0) { return 0; }

  int strIndex = 0;
  for (strIndex = 0; strIndex < OVERFLOW_BUCKET; strIndex++) {
    char *wStr = hash_bucket[hash][strIndex];

    if (!strcmp(str, wStr)) break;
  }

  for (int i = strIndex; i < lastIndex; i++) {
    strcpy(hash_bucket[hash][i], hash_bucket[hash][i+1]);
  }

  for (int i = 0; i < ORIGIN_STR_MAX_LENGTH; i++) {
    hash_bucket[hash][lastIndex][i] = 0;
  }

  return 1;
}

void show_hashtable() {
  for (int hash = 0; hash < HASH_BUCKETS; hash++) {
    printf("%02d", hash);
    if (hash_bucket[hash][0][0] == 0) {
      printf("\tNULL\n");
    } else {
      for (int i = 0; i < OVERFLOW_BUCKET; i++) {
        printf("\t%s", hash_bucket[hash][i]);
      }
      printf("\n");
    }
  }
}


