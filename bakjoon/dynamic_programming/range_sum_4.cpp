//
// Created by LEE GUNHO on 2023/04/12.
//

// 구간 합 구하기 4 : https://www.acmicpc.net/problem/11659

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int N,M;
    cin >> N >> M;


    vector<long> cache(N+1);
    cache[0] = 0;

    int k;
    for(int n=1;n<=N;n++)
    {
        cin >> k;
        cache[n] = cache[n-1] + k;
    }

    int i,j;
    for(int n=0;n<M;n++)
    {
        cin >> i >> j;
        cout << cache[j] - cache[i-1] << "\n";
    }

    return 0;
}

// 1차 : 그냥 더하면 시간 초과
// 2차 : cache 타입 int -> long
