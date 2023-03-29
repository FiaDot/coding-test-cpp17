//
// Created by LEE GUNHO on 2023/03/29.
//

// 알고리즘 수업 - 너비 우선 탐색 1 : https://www.acmicpc.net/problem/24444

/*
bfs(V, E, R) {  # V : 정점 집합, E : 간선 집합, R : 시작 정점
    for each v ∈ V - {R}
        visited[v] <- NO;
    visited[R] <- YES;  # 시작 정점 R을 방문 했다고 표시한다.
    enqueue(Q, R);  # 큐 맨 뒤에 시작 정점 R을 추가한다.
    while (Q ≠ ∅) {
        u <- dequeue(Q);  # 큐 맨 앞쪽의 요소를 삭제한다.
        for each v ∈ E(u)  # E(u) : 정점 u의 인접 정점 집합.(정점 번호를 오름차순으로 방문한다)
            if (visited[v] = NO) then {
                visited[v] <- YES;  # 정점 v를 방문 했다고 표시한다.
                enqueue(Q, v);  # 큐 맨 뒤에 정점 v를 추가한다.
            }
    }
}
 */


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int V,E,R;

const int SIZE = 100000 + 1;
vector<int> v[SIZE];
int visited[SIZE];

int cnt = 1;
int result[SIZE];


void bfs(int r)
{
    visited[r] = true;

    queue<int> q;
    q.push(r);

    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        // cout << current << "\n";
        result[current] = cnt++;

        for (int n=0;n<v[current].size();n++)
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
    // input : bidirection
    cin >> V >> E >> R;

    for(int n=0;n<E;n++)
    {
        int src,dst;
        cin >> src >> dst;

        v[src].push_back(dst);
        v[dst].push_back(src);
    }

    // sort : 오름차순 (기본)
    for(int n=1;n<=V;n++)
    {
        sort(v[n].begin(), v[n].end());
    }

    // bfs
    bfs(R);

    // output
    for(int n=1;n<=V;n++)
    {
        cout << result[n] << "\n";
    }
    return 0;
}

