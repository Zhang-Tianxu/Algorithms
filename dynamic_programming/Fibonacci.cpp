#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
/*
 * recursive fibonacci program
 */
int fib_recursion(int n) {
    if(n <= 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }
    if(n>1) {
        return fib_recursion(n-1) + fib_recursion(n-2);
    }
}

// --------------------- dynamic programming top to down -------------------
int fib_dp_top2down_in(int n,vector<int> &fib_num) {
    if(fib_num[n] >= 0) {
        return fib_num[n];
    }
    else {
        fib_num[n] = fib_dp_top2down_in(n-1,fib_num) + fib_dp_top2down_in(n-2,fib_num);
    }
    return fib_num[n];
}
int fib_dp_top2down(int n) {
    vector<int> fib_num(n+1,-1);
    fib_num[0] = 0;
    fib_num[1] = 1;
    return fib_dp_top2down_in(n,fib_num);
}

// --------------------- dynamic programming down to top -------------------
int fib_dp_down2top(int n) {
    vector<int> fib_num(n+1,-1);
    fib_num[0] = 0;
    fib_num[1] = 1;
    for(int i = 2;i <= n;i++) {
        fib_num[i] = fib_num[i-1] + fib_num[i-2];
    }
    return fib_num[n];
}

void time_test(int (*p)(int),int n) {
    time_t start, end;
    start = clock();
    cout << p(n) << endl;
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;  //输出时间（单位：ｓ）
}

int main() {
    time_test(fib_recursion,45);
    time_test(fib_dp_top2down,45);
    time_test(fib_dp_down2top,45);
}
