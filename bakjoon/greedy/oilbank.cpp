//
// Created by LEE GUNHO on 2023/04/04.
//

// 주유소 : https://www.acmicpc.net/problem/13305

/*
4
2 3 1
5 2 4 1
 */
// 18

// 1단계만 통과 ㅋㅋ

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int cnt;
    cin >> cnt;

    vector<int> dist;
    vector<int> price;

    for(int n=0;n<cnt-1;n++)
    {
        int d;
        cin >> d;
        dist.push_back(d);
    }

    for(int n=0;n<cnt;n++)
    {
        int p;
        cin >> p;
        price.push_back(p);
    }

    // 최초 시작점에서 다음 지점까지는 필수
    long long m = price[0] * dist[0];
    for(int n=1;n<cnt-1;n++)
    {
        // 이전 지점 가격과 현재지점 가격 비교해서
        // 싸다면 이전지점 가격으로 추가
        if ( price[n-1] < price[n] )
            m += price[n-1] * dist[n];
        else
            m += price[n] * dist[n];
    }

    cout << m;

    return 0;
}


