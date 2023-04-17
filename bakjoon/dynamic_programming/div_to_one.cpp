//
// Created by LEE GUNHO on 2023/04/17.
//

// 1로 만들기 : https://www.acmicpc.net/problem/1463

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;

    int dp[n+1];
    dp[1] = 0;

    for(int k=2;k<=n;k++)
    {
        dp[k] = dp[k-1] + 1;
        if ( k % 3 == 0 ) dp[k] = min(dp[k], dp[k/3] + 1);
        if ( k % 2 == 0 ) dp[k] = min(dp[k], dp[k/2] + 1);
    }

    cout << dp[n];
    return 0;
}
