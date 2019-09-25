#include <stdio.h>

/**
 * Defining struct Person to store person data
 * */
typedef struct Person {

    /**
     * property: Person's name
     **/
    char name[20];

    /**
     * property: how many car do this person has?
     **/
    int carLength;

    /**
     * Defining struct Car for storing car
     **/
    struct Car {
        /**
         * the car's name
         **/
        char name[20];

        /**
         * The Car's released Year
         **/
        int releasedYear;

    } cars[3];

// typedef-ing struct Person to Person
} Person;

/**
 * Function to print Person's data
 **/
void printPersonData(Person you) {

    // print person's name
    printf("name: %s\n", you.name);

    // print person's how many car
    printf("how many cars: %d\n", you.carLength);

    // for every car he has:
    for (int i = 0; i < you.carLength; i++) {

        // print car no.
        printf("\tcar #%d:\n", i+1);

        // print car name
        printf("\tcar name: %s\n", you.cars[i].name);

        // print car's released year
        printf("\tcar year: %d\n", you.cars[i].releasedYear);
    }
}

Person personConstructor() {
    Person person = {};

    // ask what's your name to screen
    printf("What\'s your name? : ");

    // get input and save it via scanf
    scanf("%s", (person.name));

    // ask how many cars do the person have?
    printf("How many cars do you have? : ");

    // get input and store it to car Length 
    scanf("%d", &(person.carLength));

    // Run for statement with supplied carLength value
    for (int i = 0; i < person.carLength; i++) {
        
        // print current car no.
        printf("Car #%d\n",i+1);

        // ask car name
        printf("\tCar name : ");

        // get input via scanf
        scanf("%s", (person.cars[i].name));

        // get car year
        printf("\tCar year: ");

        // get input
        scanf("%d", &(person.cars[i].releasedYear));
    }

    // return constructed structure.
    return person;
}

/**
 * definition of main function
 **/
int main() {

    // get person object from personConstructor
    Person person = personConstructor();

    // linefeed to seperate from inputs
    printf("\n\n");

    // print the saved data.
    printPersonData(person);

    // return 0 indicateing successful exit
    return 0;
}