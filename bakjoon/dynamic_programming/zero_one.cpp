//
// Created by LEE GUNHO on 2023/03/22.
//

// 01타일 : https://www.acmicpc.net/problem/1904
// 00, 1로 N개를 조합해서 만들수 있는 가짓수 % 15746 가 결과

#include <iostream>
using namespace std;

int dp[1000000];

int main()
{
    int c;
    cin >> c;
    dp[1] = 1;
    dp[2] = 2;

    for(int n=3;n<=c;n++)
    {
        dp[n] = (dp[n-1] + dp[n-2]) % 15746;
    }

    cout << dp[c] % 15746;
    return 0;
}

