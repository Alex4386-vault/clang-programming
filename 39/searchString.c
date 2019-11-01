#include <stdio.h>
#include <string.h>

char checkStr(char *searchStr, char* str) {
    int len = strlen(searchStr);
    if (strlen(str) < len) {
        return 0;
    } else {
        for (int i = 0; i < len; i++) {
            if (*(str+i) == *(searchStr+i)) {
                return 0;
            }
            return 1;
        }
    }
}

int main() {
    char searchStr[100] = {0,};
    char string[100] = {0,};

    fgets(searchStr, 100, stdin);
    fgets(string, 100, stdin);

    int i = 0, count = 0;
    while(*(string+i) != NULL) {
        printf("%d\n",i);
        if (checkStr(searchStr, string+i)) {
            i += strlen(searchStr);
            count++;
        }
        i++;
    }

    printf("%d\n", count);
    return 0;


}