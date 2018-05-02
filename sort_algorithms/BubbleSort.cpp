#include <iostream>

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
	using namespace std;
	int N;
	int i;
	cin >> N;
	float *A = new float[N];
	for(i = 0;i<N;i++)
		cin >> A[i];
	BubbleSort(A,N);
	for(i = 0;i<N;i++)
		cout << A[i] << " ";
	cout << endl;
	delete [] A;
	return 0;
}
