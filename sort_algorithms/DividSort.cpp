#include <iostream>

	template<typename T>
void Merge(T A[],int s,int m,int e)
{
	using namespace std;
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

	template<typename T>
void DivideSort(T A[],int s,int e)
{
	if(s<e)
	{
		int m = (s+e)/2;
		DivideSort(A,s,m);
		DivideSort(A,m+1,e);
		Merge(A,s,m,e);
	}
}

int main()
{
	using namespace std;
	int n;
	cin >> n;
	float *A = new float[n];
	int i;
	for(i = 0;i < n;i++)
		cin >> A[i];
	DivideSort(A,0,n-1);
	for(i = 0;i < n;i++)
		cout << A[i] << " ";
	cout << endl;
	delete [] A;
	return 0;
}
