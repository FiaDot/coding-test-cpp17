//
// Created by LEE GUNHO on 2023/03/23.
//

// 정수 삼각형 : https://www.acmicpc.net/problem/1932

#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;

    long dp[501][501] = {0L, };


    /*
        높이를 n, 가로를 k라고 함

        n=1     1
        n=2     2 3
        n=3     4 5 6
        n=4     7 8 9 10
              k 1 2 3 4

        8번이 연결 될 수 있는건 4와 5이다.
        n=4, k=2 값 8을 기준으로 보면

        max(n[3][1], n[3][2])

        이전 높이의 왼쪽, 상단 값 중 큰값과 현재 입력 받은 값을 더해서 dp 하면 됨
     */

    for(int n=1;n<=size;n++)
    {
        for(int k=1;k<=n;k++)
        {
            cin >> dp[n][k];
            dp[n][k] = max(dp[n-1][k-1], dp[n-1][k]) + dp[n][k];
        }
    }

    long ret = 0L;
    for(int n=1;n<=size;n++)
    {
        ret = max(ret, dp[size][n]);
    }

    cout << ret;
    return 0;
}
