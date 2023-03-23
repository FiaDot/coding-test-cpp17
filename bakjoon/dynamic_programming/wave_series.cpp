//
// Created by LEE GUNHO on 2023/03/23.
//

// 파도반 수열 : https://www.acmicpc.net/problem/9461

#include <iostream>
using namespace std;

int main()
{
    // 길이가 int 초과하게됨 (max n 을 체크해서 테스트)
    long dp[101] = { 1,1,1, 2,2,3,4,5,7,};

    for(int n=3;n<=100;n++)
    {
        dp[n] = dp[n-2] + dp[n-3];
    }

    int total;
    cin >> total;

    for(int c=0;c<total;c++)
    {
        int k;
        cin >> k;

        cout << dp[k-1] << endl; // 0부터 시작했으니 값은 -1 해줌
    }
    return 0;
}


