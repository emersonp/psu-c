#include <stdio.h>

#define SIZE 200
#define MAX 2000000

#define rdtsc(lo, hi) __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi))
typedef struct {
	int lo, hi;
} longpair;
typedef union {
	longpair ll;
	long long t;
} timestamp;

typedef int v4si __attribute__ ((vector_size(16)));
typedef float v4sf __attribute__ ((vector_size(16)));
typedef union {
	v4si v;
	int i[4];
} i4vector;
typedef union {
	v4sf v;
	float f[4];
} f4vector;

int main() {
	{
		int intTreshold[SIZE] = { 0 };

		timestamp timestampStart = { };
		rdtsc(timestampStart.ll.lo, timestampStart.ll.hi);

		int intCount = 0;
		float fltValue = 0.0;
		for (int intFactor = 2; intFactor < SIZE; intFactor += 1) {
			for (intCount = 2; intCount < MAX; intCount += 1) {
				fltValue = intCount * (float) (intFactor);

				fltValue = fltValue / (float) (intFactor);

				if (fltValue != intCount) {
					intTreshold[intFactor] = intCount;

					break;
				}
			}
		}

		timestamp timestampStop = { };
		rdtsc(timestampStop.ll.lo, timestampStop.ll.hi);

		timestamp timestampDifference = { };
		timestampDifference.t = timestampStop.t - timestampStart.t;

		printf("Cycles elapsed for scalar implementation: t=%llu \n", timestampDifference.t);
		for (int intFactor = 2; intFactor < SIZE; intFactor += 1) {
			printf("[%3d]=%8d  ", intFactor, intTreshold[intFactor]);
		}
		printf("\n");
	}

	{
		int intTreshold[SIZE] = { 0 };

		timestamp timestampStart = { };
		rdtsc(timestampStart.ll.lo, timestampStart.ll.hi);

		i4vector i4vectorCount = { };
		f4vector f4vectorValue = { };
		for (int intFactor = 2; intFactor < SIZE; intFactor += 1) {
			for (i4vectorCount.i[0] = 2, i4vectorCount.i[1] = 3, i4vectorCount.i[2] = 4, i4vectorCount.i[3] = 5; i4vectorCount.i[0] < MAX; i4vectorCount.v += 4) {
				f4vectorValue.f[0] = i4vectorCount.i[0];
				f4vectorValue.f[1] = i4vectorCount.i[1];
				f4vectorValue.f[2] = i4vectorCount.i[2];
				f4vectorValue.f[3] = i4vectorCount.i[3];

				f4vectorValue.v = f4vectorValue.v * (float) (intFactor);

				f4vectorValue.v = f4vectorValue.v / (float) (intFactor);

				if (f4vectorValue.f[0] != i4vectorCount.i[0]) {
					intTreshold[intFactor] = i4vectorCount.i[0];

					break;

				} else if (f4vectorValue.f[1] != i4vectorCount.i[1]) {
					intTreshold[intFactor] = i4vectorCount.i[1];

					break;

				} else if (f4vectorValue.f[2] != i4vectorCount.i[2]) {
					intTreshold[intFactor] = i4vectorCount.i[2];

					break;

				} else if (f4vectorValue.f[3] != i4vectorCount.i[3]) {
					intTreshold[intFactor] = i4vectorCount.i[3];

					break;

				}
			}
		}

		timestamp timestampStop = { };
		rdtsc(timestampStop.ll.lo, timestampStop.ll.hi);

		timestamp timestampDifference = { };
		timestampDifference.t = timestampStop.t - timestampStart.t;

		printf("Cycles elapsed for scalar implementation: t=%llu \n", timestampDifference.t);
		for (int intFactor = 2; intFactor < SIZE; intFactor += 1) {
			printf("[%3d]=%8d  ", intFactor, intTreshold[intFactor]);
		}
		printf("\n");
	}

	return 0;
}
