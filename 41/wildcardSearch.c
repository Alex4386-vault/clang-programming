#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef char *string;

// the function that searches for specific keyword. returns keyword's location at the searchStr.
int rawSearch(string keyword, string searchStr) {
  // for all index of searchstr.
  for (int i = 0; i < strlen(searchStr); i++) {
    int j = 0;

    // check for keyword.
    for (j = 0; j < strlen(keyword) && searchStr[i+j] != 0; j++) {
      if (keyword[j] != searchStr[i+j]) {
        // if it is not keyword. break.
        break;
      }
    }

    // if j reached to the keyword length. all of the 0th-to (keywordlength)-th char was same.
    // meaning found the keyword.
    if (j == strlen(keyword)) {

      // return current index.
      return i;
    }
  }

  return -1;
}

// check how mnany * in the searchQuery.
int wildcardCounter(string searchQuery) {
  int wildcardCount = 0;

  for (int i = 0; i < strlen(searchQuery); i++) {
    if (searchQuery[i] == '*') {
      wildcardCount++;
    }
  }

  return wildcardCount;
}  

// gets wildcard contained searchQuery and split by *
string *searchQueryParser(string searchQuery) {
  
  // get how many wildcard are there
  int wildcardCount = wildcardCounter(searchQuery);

  // allocate for each string's array.
  string *wildcardParsed = (string *)malloc(sizeof(string) * (wildcardCount + 1));

  // create pointer currentString and position at beginning of the search Query
  string currentString = searchQuery;

  // looping to wildcardCount +1 because we are spliting by *, so we need to add 1 more index than how many *'s in searchQuery.
  for (int i = 0; i < wildcardCount+1; i++ ) {

    // allocate memory for parsed strings.
    wildcardParsed[i] = (string)malloc((strlen(currentString) + 1) * sizeof(char));
    //printf("\t%d. %s\n", i, currentString);

    //copy until * is found.
    int j;
    for (j = 0; currentString[j] != 0 && currentString[j] != '*'; j++) {
      wildcardParsed[i][j] = currentString[j];
    }

    // update currentString to 1 index later of the *.
    currentString = currentString + j + 1;
  }
  //printf("\n");

  // return the entire parsed array.
  return wildcardParsed;
}

// the main search
int search(string searchQuery, string searchStr) {

  // check how many wildcards are out there.
  int searchQueryCount = wildcardCounter(searchQuery);

  //printf("%d\t",searchQueryCount);
  
  // get parsed search Queries.
  string *searchQueries = searchQueryParser(searchQuery);

  // set currentString as beginning of searchStr.
  string currentString = searchStr;
  
  // for all search Queries.
  for (int i = 0; i < searchQueryCount + 1; i++) {
    int len = strlen(searchQueries[i]);

    // run a search.
    int searchLoc = rawSearch(searchQueries[i], currentString);
    //    printf("%s\t", currentString);

    // if found, go forward to end of the found word.
    if (searchLoc >= 0) {
      currentString = currentString + searchLoc + len;
    } else {
      // else return false.
      return false;
    }
  }

  // if all of them are found, return true.
  return true;
}

// free all the memory for parsed searchQueries.
void freeAll(string *arr, int length) {
  for (int i = 0; i < length; i++) {
    free(arr[i]);
  }
  free(arr);
}

int main(int argCount, char *argData[]) {
  if (argCount < 2) {
    printf("Usage:\n  %s {keyword} {searchStr}\n", argData[0]);
  } /* else if (argCount < 3) {
    int wildcardCount = wildcardCounter(argData[1]);
    printf("Wildcard Parsing:\n");
    printf("\tWildcard Count: %d\n\n", wildcardCounter(argData[1]));

    string *wildcardParsed = searchQueryParser(argData[1]);
    for (int i = 0; i < wildcardCount + 1; i++) {
      printf("\t%d. ", i);
      printf("%s\n", wildcardParsed[i]);
    }
    freeAll(wildcardParsed, wildcardCount + 1);
  } */ else {
    printf("%s\n", search(argData[1], argData[2]) ? "match found!" : "match not found...");
  }
}
