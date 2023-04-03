//
// Created by LEE GUNHO on 2023/04/03.
//

// 통계학: https://www.acmicpc.net/problem/2108

/*
산술평균 : N개의 수들의 합을 N으로 나눈 값. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최빈값 : N개의 수들 중 가장 많이 나타나는 값. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
범위 : N개의 수들 중 최댓값과 최솟값의 차이
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool comp(pair<int, int>& a, pair<int,int>& b)
{
    if ( a.second == b.second )
        return a.first < b.first; // 빈도가 같을 때 숫자 작은게 앞
    return a.second > b.second; // 빈도수 큰게 앖
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int cnt;
    cin >> cnt;

    double total;

    int k;
    vector<int> values;
    for(int n=0;n<cnt;n++)
    {
        cin >> k;
        total += k;
        values.push_back(k);
    }

    sort(values.begin(), values.end());

    // 산술 평균
    // double avg = (double)total / (double)cnt;
    // long long fixedAvg = (long long)avg;
    //cout.precision(1);
    // cout << fixedAvg << "\n";

    cout <<  (int)floor( (total / cnt) + 0.5) << "\n";

    // 중앙값
    int vMid = values[cnt/2];
    cout << vMid << "\n";

    // 최빈값
    vector<pair<int, int>> v;

    for(int n=0;n<values.size();n++)
    {
        // find(check last node) -> exist -> T : update / F : insert
        int num = values[n];

        if ( v.empty() || v.back().first != num)
        {
            v.push_back({num, 1});
        }
            // if ( v.back().first == num )
        else
        {
            pair<int, int>& p = v.back();
            p.second = p.second+1;
        }
    }

    sort(v.begin(), v.end(), comp);

    if ( v[0].second == v[1].second )
        cout << v[1].first << "\n";
    else
        cout << v[0].first << "\n";

    // 범위
    cout << values.back() - values.front() << "\n";
    return 0;
}
