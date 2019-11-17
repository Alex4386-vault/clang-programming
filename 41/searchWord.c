#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef char *string;

// Find keyword from searchStr
int rawSearch(string keyword, string searchStr) {
  // for length of the search String
  for (int i = 0; i < strlen(searchStr); i++) {
    int j = 0;

    // check current index is matched with keyword
    for (j = 0; j < strlen(keyword) && searchStr[i+j] != 0; j++) {
      // if else
      if (keyword[j] != searchStr[i+j]) {
        // break
        break;
      }
    }

    // if it is a keyword
    if (j == strlen(keyword)) {
      // return base location of the keyword Found
      // in the search String.
      return i;
    }
  }
  // if it is not found, return -1.
  return -1;
}

// core searching algorithm
int search(string searchQuery, string searchStr) {
  // char pointer for current searching location
  string currentSearch;
  int count = 0;
  
  // for all index in currentSearch
  for (currentSearch = searchStr; *(currentSearch) != 0; ) {
    int len = strlen(searchQuery);
    // run search
    int searchLoc = rawSearch(searchQuery, currentSearch);
    // if it is found
    if (searchLoc >= 0) {
      //printf("Found: %d. %s @ Location. %d, CurrentSearch: %s\n", count, searchQuery, searchLoc, currentSearch);
      //printf("Length: %d\n", len);
      // increase count.
      count++;
      currentSearch = currentSearch + searchLoc + len;
    } else {
      // else increase currentSearch pointer for search in the next index.
      currentSearch++;
    }

  }
  //printf("\n");

  // return count.
  return count;
}

int main(int argCount, char *argData[]) {
  // if the argument is less than 3,
  if (argCount < 3) {
    // return usage
    printf("Usage:\n  %s {keyword} {searchStr}\n", argData[0]);
  } else {
    // else return how many matches are found.
    printf("%d matches!\n", search(argData[1], argData[2]));
  }
}
