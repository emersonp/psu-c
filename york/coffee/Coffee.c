// Coffee.c
// Andrew Cleland and Parker Harris Emerson
/*

*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int dist(int x1, int y1, int x2, int y2) {
	return (abs(x1 - x2) + abs(y1 - y2));
}

int score(int city[1001][1001], int walk, int x, int y, int dx, int dy) {
    int scoreValue = 0;
    for (int i = 1; i <= dx; i++) {
        for (int j = 1; j <= dy; j++) {
            if (city[i][j] == 1 && dist(x, y, i, j) <= walk) {
                scoreValue++;
            }
        }
    }
    return scoreValue;
}

void setToZero(int array[1001][1001], int dx, int dy) {
    for (int i = 0; i <= dx; i++) {
        for (int j = 0; j <= dy; j++) {
            array[i][j] = 0;
        }
    }
}


int main(){

	FILE *f1; // The file containing coffee data.
	int dx, dy, n, q;
	int x, y, m;
    int city[1001][1001];
    int query[21];
	int coffeecase;
    int scoreGrid[1001][1001];


	f1 = fopen("CoffeeData2.txt","r");
	// check for file open error
	if (f1 == NULL) {
		printf("\nUnable to open CoffeeData.txt\n");
		exit(1);
	}

	coffeecase = 1;
	while (1) {

			fscanf(f1,"%d %d %d %d",&dx, &dy, &n, &q);

            // Test for four zeroes
            if ((dx == 0) && (dy == 0) && (n == 0) && (q == 0)){
                // exit(1);
                break;
            }

			// Do error checking here
			if ((n > 500000) || (n < 0) || (q > 20) || (q < 1)) {
				printf("\n input error n = %d, q = %d\n",n,q);
				exit(1);
			}

			// Clear the city and scoreGrid
            setToZero(city, dx, dy);

			// Read in the coffee shop locations
			for (int i = 1; i <= n; i++){
				fscanf(f1,"%d %d", &x, &y);
				if ((x < 1) || (x > dx) || (y < 1) || (y > dy)) {
					printf("\n input error coffee shop location = %d x = %d, y = %d, dx = %d, dy = %d\n", i, x, y, dx, dy);
					exit(1);
				}
				city[x][y] = 1;
			}

			// Read in the query distances
			for(int i = 1; i <= q; i++){
				fscanf(f1,"%d", &m);
				if ((m < 0) || (m > 1000000)) {
					printf("\n input error query distance i = %d m = %d\n", i,m);
					exit(1);
				}
				query[i] = m;
			}

		// Compute the output for this case
			printf("\nCase %d:\n", coffeecase);

            for (int k = 1; k <= q; k++) {
                // For each city loc, compute score
                for (int i = 1; i <= dx; i++) {
                    for (int j = 1; j <= dy; j++) {
                        scoreGrid[i][j] = score(city, query[k], i, j, dx, dy);
                    }
                }
                // Compute winning score.
                int winnerX = 0;
                int winnerY = 0;
                for (int i = 1; i <= dy; i++) {
                    for (int j = 1; j <= dx; j++) {
                        if (scoreGrid[winnerX][winnerY] < scoreGrid[j][i]) {
                            winnerX = j;
                            winnerY = i;
                        }
                    }
                }
                printf("%d: %d (%d, %d)\n", query[k], scoreGrid[winnerX][winnerY], winnerX, winnerY);
                setToZero(scoreGrid, dx, dy);
            }


			printf("\n");
		//increment coffee case
			coffeecase++;


	}

	printf("\nAll cases are done\n");

	//close the file
	fclose(f1);
}

