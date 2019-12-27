#include <iostream>
#include "SortTester.h"

/*
 * Descriptions:
 *    A[s,e] is a set of numbers that is divided into two ordered subarray, A[s,m] and A[m+1,e]. Merge() merge them into one ordered array inplace.
 *
 * Inputs:
 *     A[] s set of numbers,
 *     s, start point.
 *     m, middle point
 *     e, end point
 *
 * Outputs:
 *     None
 */
	template<typename T>
void Merge(T A[],int s,int m,int e)
{
	int i,j,k;
	T *B = new T[(m-s+1)];
	T *C = new T[e-m];

	for(i=0;i<(m-s+1);i++)
		B[i] = A[s+i];

	for(j=0;j<(e-m);j++)
		C[j] = A[m+j+1];

	for(i=0,j=0,k=s;i<(m-s+1)&&j<(e-m);)
	{
		if(B[i]<C[j])
		{
			A[k] = B[i];
			i++;
			k++;
		}
		else
		{
			A[k] = C[j];
			j++;
			k++;
		}
	}

	while(i<(m-s+1))
		A[k++] = B[i++];
	while(j<(e-m))
		A[k++] = C[j++];

	delete [] B;
	delete [] C;
}


/*
 * Description:
 *     A[] is a set of numbers, Sort A[s,e] in place by ascending order.
 *
 * Inputs:
 *     A[]: a set of numbers
 *     s: sort range's start point, minimum value is 0
 *     e: sort range's end point, maximum value is A's length - 1
 *
 * Outputs:
 *     None
 *
 */
	template<typename T>
void MergeSort(T A[],int s,int e)
{
	if(s<e)
	{
		int m = (s+e)/2;
		MergeSort(A,s,m);
		MergeSort(A,m+1,e);
		Merge(A,s,m,e);
	}
}

int main()
{
    SortTester2(MergeSort);
}
