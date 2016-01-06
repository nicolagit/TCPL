/* Our binary search makes two tests inside the loop, when one
 * would suffice (at the price of more tests outside). Write a version with only one
 * test inside the loop and measure the difference in run-time
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAYLENGTH 1000000


/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n);
/* binsearch2 */
int binsearch2(int x, int v[], int n);

/* main */
int main()
{
	int i;
	clock_t t, search1start, search1end, search2start, search2end;
	int list[ARRAYLENGTH];
	int searchfor[ARRAYLENGTH];

/* Populating array with elements at random distance of 1-5, then print it */
	srand((unsigned) time(&t));
	list[0] = 0; //let's start with 0 in the first element
	for(i = 1; i < ARRAYLENGTH; i++) {
		list[i] = list[i-1] + (rand() % 5) + 1;
		printf("pos.%d = %d\n", i, list[i]);
	}

/* Populating array with elements to search for */
	for (i=0; i < ARRAYLENGTH; i++) {
		searchfor[i] = rand() % (5 * ARRAYLENGTH);
	}

/* Execute and measure binsearch, print also results for the search */
	search1start = clock(); 
	for (i=0; i < ARRAYLENGTH; i++) {
		printf("BINSEARCH: %d in position %d\n",
				searchfor[i],
				binsearch (searchfor[i], list, ARRAYLENGTH));
	}
	search1end = clock();

/* Execute and measure binsearch2, print also results for the search */
	search2start = clock();
	for (i=0; i < ARRAYLENGTH; i++) {
		printf("BINSEARCH2: %d in position %d\n",
				searchfor[i],
				binsearch2 (searchfor[i], list, ARRAYLENGTH));
	}
	search2end = clock();

/* Print the used time */
	printf("Measured time for binsearch: %f sec.\n", ((double) (search1end - search1start))/CLOCKS_PER_SEC);
	printf("Measured time for binsearch2: %f sec.\n", ((double) (search2end - search2start))/CLOCKS_PER_SEC);

	return 0;
}


/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else /* found match */
			return mid;
	}
	return -1; /* no match */
}

/* binsearch2 */
int binsearch2(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while ( (low < high) && (x != v[mid]) ) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid;
		else 
			low = mid + 1;
	}
	if (x == v[mid])
		return mid;
	else
		return -1; 
}
