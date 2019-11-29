#include <stdio.h>
#include <stdlib.h>

int main() {
    char buf[50];

    printf("Check about your intelligence : ");
    scanf("%[^\n]", buf);

    if (!strcmp(buf, "myeonghoe")) {
        printf("%s is Good man\n", buf);
    } else if (strstr(buf, "SHELLCODE")) {
        system("/bin/sh");
    } else {
        printf("%s is Fu**king man\n", buf);
    }

    return 0;
}