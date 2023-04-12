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

    vector<int> v;
    for(int n=0;n<N;n++)
    {
        int k;
        cin >> k;
        v.push_back(k);
    }

    for(int n=0;n<M;n++)
    {
        int i,j;
        cin >> i >> j;

        long long sum = 0;
        for(int k=i-1;k<j;k++)
        {
            sum += v[k];
        }

        cout << sum << "\n";
    }

    return 0;
}

// 1차 : 그냥 더하면 시간 초과
