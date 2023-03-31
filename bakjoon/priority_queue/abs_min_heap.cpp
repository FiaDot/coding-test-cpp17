//
// Created by LEE GUNHO on 2023/03/31.
//

// 절댓값 힙 : https://www.acmicpc.net/problem/11286

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp
{
    bool operator()(int a, int b)
    {
        if (abs(a) > abs(b))
            return true;

        if (abs(a) == abs(b) )
            return a > b;

        return false;
    }
};

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int cnt;
    cin >> cnt;

    priority_queue<int, vector<int>, cmp> q;

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