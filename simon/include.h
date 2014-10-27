#ifndef INCLUDE_H
#define INCLUDE_H

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int intSize;
	int* intData;
} numbers;

void allocNumbers(numbers* numbersHandle) {
	numbersHandle->intData = (int*) (malloc(sizeof(int) * numbersHandle->intSize));
}

void freeNumbers(numbers* numbersHandle) {
	free(numbersHandle->intData);
}

void readNumbers(char* charFile, numbers* numbersHandle) {
	FILE* fileHandle = fopen(charFile, "r");

	{
		fscanf(fileHandle, "%d", &numbersHandle->intSize);
	}

	{
		allocNumbers(numbersHandle);

		for (int intFor1 = 0; intFor1 < numbersHandle->intSize; intFor1 += 1) {
			fscanf(fileHandle, "%d", &numbersHandle->intData[intFor1]);
		}
	}

	fclose(fileHandle);
}

void readNumbervectors(char* charFile, numbers* numbersA, numbers* numbersB) {
	FILE* fileHandle = fopen(charFile, "r");

	{
		int intSize = 0;

		fscanf(fileHandle, "%d", &intSize);

		numbersA->intSize = intSize;
		numbersB->intSize = intSize;
	}

	{
		allocNumbers(numbersA);

		for (int intFor1 = 0; intFor1 < numbersA->intSize; intFor1 += 1) {
			fscanf(fileHandle, "%d", &numbersA->intData[intFor1]);
		}
	}

	{
		allocNumbers(numbersB);

		for (int intFor1 = 0; intFor1 < numbersB->intSize; intFor1 += 1) {
			fscanf(fileHandle, "%d", &numbersB->intData[intFor1]);
		}
	}

	fclose(fileHandle);
}

#endif
