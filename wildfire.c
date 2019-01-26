//wildfire program
#include <stdio.h>
#include <stdlib.h>

char genTree(int startPercent, int Density){ //This function decides whether a space in the array will be populated, or burning
	int r = (rand() % (100) + 1); //get random number
	char tree;
	if (r <= Density){ //if less, it will be a tree
		int d = (rand() % (100) +1); //get random number
		if (d <= startPercent){ //if the random number is less than startPercent, make it burn
			tree = '*';
		}
		if (d > startPercent){ //if less, make it not burn
			tree = 'Y';
		}
	}
	if (r > Density){ //if greater, then it will be empty
		tree = '_';
	}
	return tree; //return the tree

}
int main (int argc, char *argv[]){
	if (argc < 4){ //check if user entered a command line argument
		fputs("No argument\n", stderr);
	}
	else if (argc > 4){ //check if too many were entered
		fputs("Too many arguments\n", stderr);
	}
	else {
		srand(time(NULL));
		char *p; //declare pointer for conversion
		int i,n; //declare int for for loop
		int size = strtol(argv[1], &p, 0); //convert the first command argument to int
		int perc = strtol(argv[2], &p, 0); //convert the seconds command argument to int
		int density = strtol(argv[3], &p, 0);
		char array[size][size]; //create array based on what user entered
		for (n=0; n<size; n++){ //for loop, size-number of iterations
			for (i=0; i<size; i++){ //secondary for loop with the same number
				array[n][i] = genTree(perc, density); //put tree into the array
				printf("%c", array[n][i]); //print array at that position
			}
			printf("\n"); //newline
		}
		printf("\nSize entered: %d\n", size); //print size entered
	}
	return 0; //exit
}
