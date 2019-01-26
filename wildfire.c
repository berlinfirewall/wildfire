//wildfire program

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
	if (argc == 1){ //check if user entered a command line argument
		fputs("No argument\n", stderr);
	}
	else if (argc > 2){ //check if too many were entered
		fputs("Too many arguments\n", stderr);
	}
	else {
		char *p; //declare pointer for conversion
		int i,n; //declare int for for loop
		int size = strtol(argv[1], &p, 0); //convert the first command argument to long int
		char array[size][size]; //create array based on what user entered
		for (n=0; n<size; n++){ //for loop, size-number of iterations
			for (i=0; i<size; i++){ //secondary for loop with the same number, the
				array[n][i] = 'Y'; //put 'Y' into the array
				printf("%c", array[n][i]); //print array at that position
			}
			printf("\n"); //newline
		}
		printf("\nSize entered: %d\n", size); //print size entered
	}
	return 0; //exit
}
