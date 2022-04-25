#include <iostream>

template<typename T>
void InsertSort(T A[],int n)
{
	using namespace std;
	int i,j;
	T tmp;
	for(j=1;j<n;j++)
	{
		tmp=A[j];
		for(i=j-1;i>=0;i--)
		{
			if(tmp<A[i])
				A[i+1]=A[i];
			else
				break;
		}
		A[i+1] = tmp;
		for(int k = 0;k<n;k++)
			cout << A[k] << " " ;
		cout << endl;
	}
}

int main()
{
	using namespace std;
	int n;
	int i;
	cin >> n;
	float *A = new float[n];
	for(i = 0;i<n;i++)
		cin >> A[i];
	InsertSort(A,n);
	for(i = 0;i<n;i++)
		cout << A[i] << " ";
	cout << endl;
	delete [] A;
	return 0;
}
