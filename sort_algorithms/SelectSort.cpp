#include <iostream>

template<typename T>
void SelectSort(T A[],int n)
{
	T min= A[0];
	int min_p = 0;
	int i,j;
	for(i=0;i<n;i++)
	{
		min = A[i];
		min_p = i;
		for(j=i+1;j<n;j++)
			if(min > A[j])
			{
				min = A[j];
				min_p = j;
			}
		for(j = min_p;j>=i;j--)
			A[j] = A[j-1];
		A[i]=min;
	}
}

int main()
{
	using namespace std;
	int n;
	cin >> n;
	float *A = new float[n];
	int i,j;
	for(i = 0;i<n;i++)
		cin >> A[i];
	SelectSort(A,n);
	for(i = 0;i<n;i++)
		cout << A[i] << " ";
	cout << endl;
	delete [] A;
	return 0;
}
