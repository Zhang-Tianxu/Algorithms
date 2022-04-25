#include "SortTester.h"
#include <math.h>

void SortTester(void (*sorter_p)(float *, int))
{
    struct timespec tn_s;
    struct timespec tn_e;
    using namespace std;

	int N;
	int i;
    for(int j = 1;j < 6;j++)
    {
        N = pow(10,j);
        float *A = new float[N];
        for(i = 0;i<N;i++)
            A[i] = (rand() % 1000) - 500;

        clock_gettime(CLOCK_REALTIME, &tn_s);
        sorter_p(A,N);
        clock_gettime(CLOCK_REALTIME, &tn_e);

        if(tn_e.tv_nsec >= tn_s.tv_nsec)
        {
            cout << "sort " << N << " numbers take time " << tn_e.tv_sec - tn_s.tv_sec << "s " << tn_e.tv_nsec - tn_s.tv_nsec << "ns." <<endl;
        }
        else
        {
            cout << "sort " << N << " numbers take time " << tn_e.tv_sec - tn_s.tv_sec - 1 << "s " << tn_e.tv_nsec - tn_s.tv_nsec + 1000000000 << "ns." <<endl;
        }
        delete [] A;
    }
}

void SortTester2(void (*sorter_p)(float *, int, int))
{
    struct timespec tn_s;
    struct timespec tn_e;
    using namespace std;

	int N;
	int i;
    for(int j = 1;j < 6;j++)
    {
        N = pow(10,j);
        float *A = new float[N];
        for(i = 0;i<N;i++)
            A[i] = (rand() % 1000) - 500;

        clock_gettime(CLOCK_REALTIME, &tn_s);
        sorter_p(A,0,N-1);
        clock_gettime(CLOCK_REALTIME, &tn_e);

        if(tn_e.tv_nsec >= tn_s.tv_nsec)
        {
            cout << "sort " << N << " numbers take time " << tn_e.tv_sec - tn_s.tv_sec << "s " << tn_e.tv_nsec - tn_s.tv_nsec << "ns." <<endl;
        }
        else
        {
            cout << "sort " << N << " numbers take time " << tn_e.tv_sec - tn_s.tv_sec - 1 << "s " << tn_e.tv_nsec - tn_s.tv_nsec + 1000000000 << "ns." <<endl;
        }
        delete [] A;
    }
}
