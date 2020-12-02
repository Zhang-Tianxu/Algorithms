/*
 * 问题： 给定n个整数（可能为负数）组成的序列a[1],a[2],a[3],…,a[n]
 * 求该序列如a[i]+a[i+1]+…+a[j]的子段和的最大值
*/
#include <iostream>
#include "tester.h"

#define LISTMAX 1000

template <typename T>
T max_num(T list[],int b,int e)
{//return max num of list from b to e
	int i;
	T max = list[b-1];
	for(i=b;i<e;i++)
		if(list[i] > max)
			max = list[i];
	return max;
}

template <typename T>
T max_child_segment(T list[],int b,int e)
{//find the max child segment of list from b to e and return it's add
	T max[LISTMAX];//max[j] = max(list[i]+list[i+1]+...+list[j])
	max[b-1] = list[b-1];
	int i;
	for(i=b;i<e;i++)
	{
		if(max[i-1] > 0)
			max[i] = max[i-1] + list[i];
		else
			max[i] = list[i];
	}
	return max_num(max,b,e);
}

int main()
{
	using namespace std;
	double list[LISTMAX];
	int N;
	cout << "Please input the length of list." << endl;
	cin >> N;
	int i;
	cout << "Please input the list(seperate by space)." <<endl;
	for(i = 0;i<N;i++)
		cin >> list[i];
	cout << "The max child segment of list is " << max_child_segment(list,1,N) <<endl;
	return 0;

}
