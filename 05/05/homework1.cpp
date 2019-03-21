// Recommended Compiler: Visual C++ MSBUILD
// this source code requires C compiler which supports C11.

#include <stdio.h>

// If you are using gcc (GCC: GNU C Compiler) or 
// any compiler doesn't support C11 or Microsoft-Styled C language,
//
// add this preprocessor before you compile this script.
//
// #define scanf_s scanf

int main() {

	// START INIT SECTION

	// Initalize variable for user input. (int)
	int userInput = 0;

	// END INIT SECTION



	// START USER INPUT SECTION

	// declare a boolean vairable of inputted variable is ok
	bool isInputValid = false;

	// use while to check validity.
	while (!isInputValid) {
		// ask user about what is initial velocity.
		// \b is a escape character for backspace.
		printf("Input five digit integer to get each digits: ?????\b\b\b\b\b");

		// using scanf_s to securely get data from user
		// => prevent stack overflow
		scanf_s("%d", &userInput);

		// validate user Input
		if ((userInput > 0) && (userInput < 100000)) {
			// This is a appropriate userInput.
			// set isInputValid to true to get out of this loop
			isInputValid = true;
		}
		else {
			// This is a invalid userInput.
			printf("Invalid User Input was detected.\nPlease enter FIVE DIGIT INTEGER to get each digits.\n");
		}
	}

	// END USER INPUT SECTION



	// START OUTPUT SECTION

	// ECMAScript: ParseInt() is new Math.floor()
	// Actually i'd like to use for loop with <Math.h>'s pow function
	// but was not told in lecture... :(

	printf("%d   ", userInput / 10000);
	userInput -= ((int)userInput / 10000 * 10000);
	printf("%d   ", userInput / 1000);
	userInput -= ((int)userInput / 1000 * 1000);
	printf("%d   ", userInput / 100);
	userInput -= ((int)userInput / 100 * 100);
	printf("%d   ", userInput / 10);
	userInput -= ((int)userInput / 10 * 10);
	printf("%d", userInput / 1);
	userInput -= ((int)userInput / 1 * 1);

	// END OUTPUT SECTION

}