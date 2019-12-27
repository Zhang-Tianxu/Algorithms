#include <iostream>

#include <cstdlib> // for srand() & rand
#include <time.h> // for seed

#include "SortTester.h"

/*
 * description:
 *     Sort input array A in place by ascending order.
 *
 * inputs:
 *     An array A and it's length n
 *
 * outputs:
 *     None
 *
 */
template <typename T>
void BubbleSort(T A[],int n)
{
	int i,j;
	T tmp;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(A[i]>A[j])
			{
				tmp = A[i];
				A[i]= A[j];
				A[j] = tmp;
			}
		}
}
int main()
{
    SortTester(BubbleSort);
}
