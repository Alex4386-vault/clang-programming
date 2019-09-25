#include <stdio.h>
#include <stdlib.h>

// 메모리가 기침하면? calloc calloc 
//  - 아 노잼

struct Person {
    char name[30];
    struct Person *acquasntances;
    char isInNonLan;
};

int main() {
    struct Person *person;
    
    person = (struct Person *)malloc(sizeof(struct Person) * 2);
    if (person == NULL) {
        printf("WARNING! SYSTEM FUCKED! NO MEMORY!!!!");
        return 1;
    }

    printf("What\'s your name, What\'s, What\'s your name: ");
    
    char* buffer = (char *)malloc(sizeof(char)*30);
    getline(buffer, 29, stdin);

    printf("%s", person->name);
}