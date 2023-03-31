//
// Created by LEE GUNHO on 2023/03/31.
//

// 최대 힙 : https://www.acmicpc.net/problem/11279

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // 시간 초과 발생 문제
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int cnt;
    cin >> cnt;

    priority_queue<int, vector<int>, less<> > q;

    for(int n=0;n<cnt;n++)
    {
        int v;
        cin >> v;

        if ( 0 != v )
        {
            q.push(v);
            continue;
        }

        if ( q.empty() )
        {
            cout << "0" << "\n";
            continue;
        }

        cout << q.top() << "\n";
        q.pop();
    }
}

