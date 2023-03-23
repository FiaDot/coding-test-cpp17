//
// Created by LEE GUNHO on 2023/03/23.
//

// RGB 거리 : https://www.acmicpc.net/problem/1149

#include <iostream>
using namespace std;

int main()
{
    int house;
    cin >> house;

    long dp[1001][3] = {0L, }; // 값 커지니 타입 주의!, 초기화.
    int cost[3];

    for(int n=1;n<=house;n++)
    {
        cin >> cost[0] >> cost[1] >> cost[2];

        // 현재가 R 이면 이전 G, 이전 B중 낮은값
        dp[n][0] = min(dp[n-1][1], dp[n-1][2]) + cost[0];
        dp[n][1] = min(dp[n-1][0], dp[n-1][2]) + cost[1];
        dp[n][2] = min(dp[n-1][0], dp[n-1][1]) + cost[2];
    }

    int ret = min(min(dp[house][0], dp[house][1]), dp[house][2]);
    cout << ret;
    return 0;
}

