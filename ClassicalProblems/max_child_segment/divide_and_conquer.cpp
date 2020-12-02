/*
 * 问题： 给定n个整数（可能为负数）组成的序列a[1],a[2],a[3],…,a[n]
 * 求该序列如a[i]+a[i+1]+…+a[j]的子段和的最大值
*/
#include <iostream>

#include "tester.h"

template <typename T>
T max(T a,T b,T c)
{//return max of a,b,c
	if(a>b)
	{
		if(a>c)
			return a;
		else
			return c;
	}
	else
	{
		if(b>c)
			return b;
		else
			return c;
	}
}


template <typename T>
T max_child_segment(T list[],int b,int e)
{//find a max child segment of list from b to e and return it's add
	int m = (b + e) / 2;
	T sum,left_sum,right_sum;
	T left_max,right_max;
	if(b == e)
		return list[b];
	else
	{
		left_sum = max_child_segment(list,b,m);
		right_sum = max_child_segment(list,m+1,e);
		sum = 0;
		left_max = 0;
		int i;
		for(i=m-1;i>=b-1;i--)
		{
			sum += list[i];
			if(left_max < sum)
				left_max = sum;
		}
		sum = 0;
		right_max = 0;
		for(i=m;i<e;i++)
		{
			sum += list[i];
			if(right_max < sum)
				right_max = sum;
		}
		sum = left_max + right_max;
		return max(sum,left_sum,right_sum);
	}
}

int main()
{
	using namespace std;
	double list[5000];
	int N;
	cout << "Please enter the length of list." << endl;
	cin >> N;
	int i;
	cout << "Please enter the list." <<endl;
	for(i=0;i<N;i++)
		cin >> list[i];
	cout << "The max child segment of list is " << max_child_segment(list,1,N) << endl;

    tester();
	return 0;

}

