#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENTS 50

/* shellsort: sort v[0],,,v[n-1] into increasing order */
void shellsort(int v[], int n);

int main()
{
	int list[ELEMENTS];
	int i;
	clock_t t;

/* Populating array with random elements */
	printf("\nOriginal array:\n");
	srand((unsigned) time(&t));
	for (i=0; i<ELEMENTS; i++) {
		list[i] = rand() % ELEMENTS;
		printf("%3d,", list[i]);
	} 
	printf("\n");

	shellsort(list, ELEMENTS);

	printf("\nAfter shellsort:\n");
	for (i=0; i<ELEMENTS; i++) {
		printf("%3d,", list[i]);
	} 
	printf("\n");


}

/* shellsort: sort v[0],,,v[n-1] into increasing order */
void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
}
