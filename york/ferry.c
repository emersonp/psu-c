/* Copyright (c) 2014 Parker Harris Emerson
 * Splits a list of ships into two queues of weight equal to within 2%.
 */

#define _BSD_SOURCE
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numCars = 0, portCars = 0, queueCars = 0;
    float portWeight = 0, starboardWeight = 0;
    float lowerBound = 0, upperBound = 0, ferryWeight = 0;
    float* carArr = NULL;

    FILE * fileHandle;
    {

        fileHandle = fopen("ferryData.txt", "r");
        printf("\n\n");

        fscanf(fileHandle, "%d", &numCars);
        printf("Number of vehicles: %d\n", numCars);
        carArr = (float*)(malloc(sizeof(float) * numCars));

        for (int i = 0; i < numCars; i++) {
            fscanf(fileHandle, "%f", &carArr[i]);
        }
        
        float tmpWeight = 0;
        for (int i = 0; i < numCars; i++) {
            for (int j = i + 1; j < numCars; j++) {
                if (carArr[i] < carArr[j]) {
                    tmpWeight = carArr[i];
                    carArr[i] = carArr[j];
                    carArr[j] = tmpWeight;
                }
            }
        }

        for (int i = 0; i < numCars; i++) {
            ferryWeight += carArr[i];
        }

        lowerBound = ferryWeight * 0.49;
        upperBound = ferryWeight * 0.51;

        while (queueCars < numCars) {
            if (portWeight < lowerBound) {
                if (portWeight + carArr[queueCars] < upperBound) {
                    portWeight += carArr[queueCars];
                    portCars++;
                } else {
                    starboardWeight += carArr[queueCars];
                }
            } else {
                starboardWeight += carArr[queueCars];
            }
            queueCars++;
        }

        if (portWeight < lowerBound || portWeight > upperBound || starboardWeight < lowerBound || starboardWeight > upperBound) {
            printf("\nFerry not within 2%%.\n\n");
        }

        printf("Total Weight: %f\nPort Weight: %f\nStarboard Weight: %f\nPort Cars: %d\nStarboard Cars: %d\n", (portWeight + starboardWeight), portWeight, starboardWeight, portCars, (numCars - portCars));

    }
    fclose(fileHandle);
    return 0;
}
