/*
 *              数字三角形
 *    		    7
 *	          3   8
 *	        8   1   0
 *	      2   7   4   4
 *	    4   5   2   6   5
 *
 * 在上面的数字三角形中寻找一条从顶部到底边的路径
 * 使得路径上所经过的数字之和最大。
 * 路径上的每一步都只能往左下或 右下走。
 * 只需要求出这个最大和即可，不必给出具体路径。
 * 三角形的行数大于1小于等于100，数字为 0 - 99
 * 输入格式：
 *5      //表示三角形的行数    接下来输入三角形
 *7
 *3   8
 *8   1   0
 *2   7   4   4
 *4   5   2   6   5
 *要求输出最大和
 */
#include <iostream>
#include <iomanip>

int NT[100][100];

	template <typename T>
T max(T a,T b)
{
	return a>b?a:b;
}

int NumTriangle(int level)
{
	int maxnum[100];
	int i,j;
	for(i=0;i<level;i++)
		maxnum[i] = NT[level-1][i];
	for(i=level - 2;i>=0;i--)
		for(j=0;j<=i;j++)
			maxnum[j]= max((NT[i][j] + maxnum[j]),(NT[i][j] + maxnum[j+1]));
	return maxnum[0];
}

int main()
{
	using namespace std;
	cout << "please enter the level of number triangle." << endl;
	int level;
	cin >> level;
	int i,j;
	cout << "Please enter the number triangle." << endl;
	for(i=0;i<level;i++)
		for(j=0;j<=i;j++)
			cin >> NT[i][j];
	for(i=0;i<level;i++)
	{
		for(j=0;j<=i;j++)
			cout << setw(5) << NT[i][j];
		cout << endl;
	}
	cout << "The max num of path is " << NumTriangle(level) << endl;
	return 0;
}
