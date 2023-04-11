//
// Created by LEE GUNHO on 2023/04/11.
//


// 이항 계수 1 : https://www.acmicpc.net/problem/11050

// 5 2
// 10

#include <iostream>
using namespace std;

int fact(int k)
{
    if ( k > 0 )
        return k * fact(k-1);
    return 1;
}

int main()
{
    int n,r;
    cin >> n >> r;

    cout << fact(n) / (fact(r) * fact(n-r));
    return 0;
}
