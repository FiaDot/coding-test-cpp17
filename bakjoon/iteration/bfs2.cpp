//
// Created by LEE GUNHO on 2023/03/30.
//

// 알고리즘 수업 - 너비 우선 탐색 2 : https://www.acmicpc.net/problem/24445

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,R;

const int SIZE = 100000 +1;
vector<int> v[SIZE];
int visited[SIZE];

int result[SIZE];
int cnt = 1;

void bfs(int p)
{
    visited[p] = true;

    queue<int> q;
    q.push(p);

    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        result[current] = cnt++;

        for(int n=0;n<v[current].size();n++)
        {
            int next = v[current][n];
            if ( visited[next] )
                continue;

            visited[next] = true;
            q.push(next);
        }
    }
}

int main()
{
    // input
    cin >> N >> M >> R;

    for(int n=0;n<M;n++)
    {
        int s,d;

        cin >> s >> d;
        v[s].push_back(d);
        v[d].push_back(s);
    }

    // sort 내림차순
    for(int n=1;n<=N;n++)
    {
        sort(v[n].begin(), v[n].end(), greater<int>());
    }

    // bfs
    bfs(R);

    // output
    for(int n=1;n<=N;n++)
    {
        cout << result[n] << "\n";
    }

    return 0;
}
