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

	if (argc < 5){ //check if user entered a command line argument
		fputs("Too Little Arguments\nCorrect Format: ./wildfire <Size> <Percent Burning> <Density> <Iterations>\n", stderr);
	}
	else if (argc > 5){ //check if too many were entered
		fputs("Too Many Arguments\nCorrect Format: wildfire <Size> <Percent Burning> <Density> <Iterations>\n", stderr);
	}
	else {
		srand(time(NULL));
		char *p; //declare pointer for conversion
		int i,n,g; //declare int for for loop
		int size = strtol(argv[1], &p, 0); //convert the first command argument to int
		int perc = strtol(argv[2], &p, 0); //convert the seconds command argument to int
		int density = strtol(argv[3], &p, 0); //convert the third command argument to int
		int iterations = strtol(argv[4], &p, 0); //convert the fourth command argument to int
		char array[size][size]; //create array based on what user entered
		struct near adjacent[size][size];
		for (n=0; n<size; n++){ //for loop, size-number of iterations //n is ROWS
			for (i=0; i<size; i++){ //secondary for loop with the same number //i IS COLUMNS
				array[n][i] = genTree(perc, density); //put tree into the array
				printf("%c", array[n][i]); //print array at that point
			}
			printf("\n");
		}
		printf ("Initial Iteration\n");
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
		for (g=0; g<iterations; g++){
			for (n=0; n<size; n++){
				for (i=0; i<size; i++){
					if (array[n][i] == "*"){
                                                array[n][i] = "_";
                                        }
					else if (array[n][i] == "Y"){
						if (adjacent[n][i].N == "*" && (adjacent[n][i].S == "*" || adjacent[n][i].E == "*" || adjacent[n][i].W == "*" || adjacent[n][i].NW == "*" || adjacent[n][i].NE == "*" || adjacent[n][i].SW == "*" || adjacent[n][i].SE == "*")){
							array[n][i] = "*";
						}
						else if (adjacent[n][i].S == "*" && (adjacent[n][i].N == "*" || adjacent[n][i].E == "*" || adjacent[n][i].W == "*" || adjacent[n][i].NW == "*" || adjacent[n][i].NE == "*" || adjacent[n][i].SW == "*" || adjacent[n][i].SE == "*")){
                                        	        array[n][i] = "*";
                                        	}
						else if (adjacent[n][i].E == "*" && (adjacent[n][i].N == "*" || adjacent[n][i].S == "*" || adjacent[n][i].W == "*" || adjacent[n][i].NW == "*" || adjacent[n][i].NE == "*" || adjacent[n][i].SW == "*" || adjacent[n][i].SE == "*")){
                                        	        array[n][i] = "*";
                                        	}
						else if (adjacent[n][i].W == "*" && (adjacent[n][i].N == "*" || adjacent[n][i].E == "*" || adjacent[n][i].S == "*" || adjacent[n][i].NW == "*" || adjacent[n][i].NE == "*" || adjacent[n][i].SW == "*" || adjacent[n][i].SE == "*")){
                                        	        array[n][i] = "*";
                                        	}
						else if (adjacent[n][i].NW == "*" && (adjacent[n][i].N == "*" || adjacent[n][i].S == "*" || adjacent[n][i].E == "*" || adjacent[n][i].W == "*" || adjacent[n][i].NE == "*" || adjacent[n][i].SW == "*" || adjacent[n][i].SE == "*")){
                                        	        array[n][i] = "*";
                                        	}
						else if (adjacent[n][i].NE == "*" && (adjacent[n][i].N == "*" || adjacent[n][i].S == "*" || adjacent[n][i].E == "*" || adjacent[n][i].NW == "*" || adjacent[n][i].W == "*" || adjacent[n][i].SW == "*" || adjacent[n][i].SE == "*")){
                                        	        array[n][i] = "*";
                                        	}
						else if (adjacent[n][i].SW == "*" && (adjacent[n][i].N == "*" || adjacent[n][i].S == "*" || adjacent[n][i].E == "*" || adjacent[n][i].NW == "*" || adjacent[n][i].NE == "*" || adjacent[n][i].W == "*" || adjacent[n][i].SE == "*")){
                                        	        array[n][i] = "*";
                                        	}
						else if (adjacent[n][i].SE == "*" && (adjacent[n][i].S == "*" || adjacent[n][i].E == "*" || adjacent[n][i].W == "*" || adjacent[n][i].NW == "*" || adjacent[n][i].NE == "*" || adjacent[n][i].SW == "*" || adjacent[n][i].W == "*")){
                                        	        array[n][i] = "*";
                                        	}
					}
					array[n][i] = genTree(perc, density); //put tree into the array
		                	printf("%c", array[n][i]); //print array at that point
				}
				printf("\n"); 
			}
			printf ("Iterations: %d\n\n", g);
		}
        	printf("\nSize entered: %d\n", size); //print size entered
	}
	return 0; //exit
}


