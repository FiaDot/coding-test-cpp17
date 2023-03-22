//
// Created by LEE GUNHO on 2023/03/22.
//

// 알고리즘 수업 - 피보나치 수 1 : https://www.acmicpc.net/problem/24416

#include <iostream>
using namespace std;

int cntRecursive = 0;
int cntTopdown = 0;

int fib(int n) {
    if (n == 1 || n == 2)
    {
        cntRecursive++;
        return 1; // # 코드1
    }

    return (fib(n - 1) + fib(n - 2));
}


int fibonacci(int n) {
    int f[41] = {0,};
    f[1] = f[2] = 1;

    for (int i=3;i<=n;i++) { // n까지 포함!
        // f[i] <- f[i - 1] + f[i - 2];  # 코드2
        f[i] = f[i-1] + f[i-2];
        cntTopdown++;
    }

    return f[n];
}

int main()
{
    int n;
    cin >> n;

    fib(n);
    fibonacci(n);

    cout << cntRecursive << ' ' << cntTopdown;
    return 0;
}
