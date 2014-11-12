#include <stdio.h>

#define SIZE 200
#define MAX 2000000

#define rdtsc(low,high) asm volatile ("rdtsc" : "=a" (low), "=d" (high))
typedef struct {int lo,hi;} longpair;
typedef union { longpair ll; long long t; } timestamp;

int main() {
	float f;
	int cnt, factor, done, thresh[SIZE];
	timestamp a,b,c;

  	rdtsc(a.ll.lo,a.ll.hi);
  	for (factor = 2; factor < SIZE; factor++) {
    		thresh[factor]=0;
   		cnt = 2;
		done = 0;
		while (!done && (cnt < MAX)) {
			f = (float) cnt*factor;
			f = f/factor;
			if (f != (float) cnt) {
				done = 1;
				thresh[factor] = cnt;
				break;
			}
			cnt++;
		}
  	}
  	rdtsc(b.ll.lo,b.ll.hi);
  	c.t = b.t-a.t;
  	printf("Cycles elapsed for scalar implementation: t=%llu \n", c.t);
  	for (factor = 2; factor < SIZE; factor++)
		printf("[%3d]=%8d  ",factor,thresh[factor]);
	printf("\n"); 

	/*	VECTOR IMPLEMENTATION HERE	*/

	return 0;
}
