//
// Created by LEE GUNHO on 2023/03/31.
//

// 최소 힙 : https://www.acmicpc.net/problem/1927

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int cnt;
    cin >> cnt;

    priority_queue<int, vector<int>, greater<> > q;

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

    return 0;
}