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
		tree = ' ';
	}
	return tree; //return the tree

}

int main (int argc, char *argv[]){
	struct near{
	        char N;
	        char S;
	        char E;
	        char W;
	        char NE;
	        char NW;
	        char SE;
	        char SW;
	};

	if (argc < 4){ //check if user entered a command line argument
		fputs("No argument\n", stderr);
	}
	else if (argc > 4){ //check if too many were entered
		fputs("Too many arguments\n", stderr);
	}
	else {
		srand(time(NULL));
		char *p; //declare pointer for conversion
		int i,n,g; //declare int for for loop
		int size = strtol(argv[1], &p, 0); //convert the first command argument to int
		int perc = strtol(argv[2], &p, 0); //convert the seconds command argument to int
		int density = strtol(argv[3], &p, 0);
		char array[size][size]; //create array based on what user entered
		struct near adjacent[size][size];
		for (n=0; n<size; n++){ //for loop, size-number of iterations //n is ROWS
			for (i=0; i<size; i++){ //secondary for loop with the same number //i IS COLUMNS
				array[n][i] = genTree(perc, density); //put tree into the array
				printf("%c", array[n][i]); //print array at that point
					
			}
			printf("\n");
		}
		for (n=0; n<size; n++){
			for (i=0; i<size; i++){
				if (n>0){ //N
                                        adjacent[n][i].N = array[n-1][i];
                                }
                                else {
                                        adjacent[n][i].N = '0';
                                }

                                if (n<(size-1)){ //S
                                        adjacent[n][i].S = array[n+1][i];
                                }
                                else {
                                        adjacent[n][i].S = '0';
                                }
                                if (i<(size-1)){ //E
                                        adjacent[n][i].E = array[n][i+1];
                                }
                                else {
                                        adjacent[n][i].E = '0';
                                }
                                if (i>0){ //W
                                        adjacent[n][i].W = array[n][i-1];
                                }
                                else {
                                        adjacent[n][i].W = '0';
                                }

                                if (n>0 && i<(size-1)){
                                        adjacent[n][i].NE = array[n-1][i+1];
                                }
                                else {
                                        adjacent[n][i].NE = '0';
                                }

                                if (n>0 && i>0){
                                        adjacent[n][i].NW = array[n-1][i-1];
                                }
                                else {
                                        adjacent[n][i].NW = '0';
                                }

                                if (n<(size-1) && i<(size-1)){
                                        adjacent[n][i].SE = array[n+1][i+1];
                                }
                                else {
                                        adjacent[n][i].SE = '0';
                                }

                                if (n<(size-1) && i>0){
                                        adjacent[n][i].SW = array[n+1][i-1];
                                }
                                else {
                                        adjacent[n][i].SW = '0';
                                }
			}
		}
		printf("%c\n", adjacent[2][2].N);
		printf("%c\n", adjacent[2][2].E);
		printf("%c\n", adjacent[2][2].S);
		printf("%c\n", adjacent[2][2].W);
		printf("%c\n", adjacent[2][2].NW);
                printf("%c\n", adjacent[2][2].NE);
                printf("%c\n", adjacent[2][2].SW);
                printf("%c\n", adjacent[2][2].SE);

		printf("\nSize entered: %d\n", size); //print size entered
	}
	return 0; //exit
}
