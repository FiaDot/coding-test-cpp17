//
// Created by LEE GUNHO on 2023/03/23.
//

// 연속합 : https://www.acmicpc.net/problem/1912

#include <iostream>
using namespace std;

int main()
{
    // input
    int cnt;
    cin >> cnt;

    int arr[cnt+1];
    for(int n=0;n<cnt;n++)
    {
        cin >> arr[n];
    }

    int dp[cnt];
    int ret = dp[0] = arr[0]; // 초기 비교값 설정

    for(int n=1;n<cnt;n++)
    {
        dp[n] = max(arr[n], dp[n-1] + arr[n]);
        ret = max(ret, dp[n]);
    }

    cout << ret;
    return 0;
}