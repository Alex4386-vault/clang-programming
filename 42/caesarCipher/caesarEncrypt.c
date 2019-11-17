#include <stdio.h>

#define __ENCRYPT__


// check whether this letter is lowercase
char isLowerCase(char letter) { return (letter <= 'z' && letter >= 'a'); }

// check whether this letter is uppercase
char isUpperCase(char letter) { return (letter <= 'Z' && letter >= 'A'); }

// check whether this letter is alphabet
char isInAlphabet(char letter) { return isUpperCase(letter) || isLowerCase(letter); }

#ifdef __ENCRYPT__

// encrypt single letter with specified shift. returns encrypted character.
char encryptLetter(char letter, int shift) {
    char lower = isLowerCase(letter);

    // since it is encryption, shift value should be added. since it is looping, 
    // it should calculated with the remainder
    return (((letter - (lower ? 'a':'A')) + shift) % 26) + (lower ? 'a':'A');
}

// encrypt file. utilizing encrypt:etter function
void encrypt(FILE *input, FILE* output, int shift) {
    // for every character in input
    for (char a = fgetc(input); !feof(input); a = fgetc(input)) {
        // check is it an alphabet
        if (isInAlphabet(a)) {
            // then encrypt and write to output
            fputc(encryptLetter(a, shift), output);
        } else {
            // just write it.
            fputc(a, output);
        }
    }
}

#else

// decrypt single letter with specified shift. returns decrypted character.
char decryptLetter(char letter, int shift) {
    char lower = isLowerCase(letter);

    // since it is decryption, shift value should be subtracted. since it is looping, 
    // it should calculated with the remainder, 26 was added because of C's interpretation
    // of modulo in negative numbers.
    return (((letter - (lower ? 'a':'A')) + 26 - shift) % 26) + (lower ? 'a':'A');
}

// decrypt file. utilizing decryptLetter function
void decrypt(FILE *input, FILE* output, int shift) {
    // for every character in input
    for (char a = fgetc(input); !feof(input); a = fgetc(input)) {
        // check is it an alphabet
        if (isInAlphabet(a)) {
            // then decrypt and write to output
            fputc(decryptLetter(a, shift), output);
        } else {
            // just write it.
            fputc(a, output);
        }
    }
}
#endif

int main() {

    // open file.
#ifdef __ENCRYPT__
    FILE *input = fopen("original.txt", "r");
    FILE *output = fopen("cypher.txt", "w");
#else
    FILE *input = fopen("cypher.txt", "r");
    FILE *output = fopen("decrypted.txt", "w");
#endif

    // exception handling
    if (input == NULL || output == NULL) {
        printf("[ERROR] couldn't open file\nCheck disk S.M.A.R.T. or file permissions!\n");
        return 1;
    }

    // ask user shift value.
    printf("Shift: ");
    int shift = 0;
    scanf("%d", &shift);

#ifdef __ENCRYPT__
    // call encrypt function
    encrypt(input, output, shift);
#else
    decrypt(input, output, shift);
#endif

    // close file pointer
    fclose(input);
    fclose(output);




}

