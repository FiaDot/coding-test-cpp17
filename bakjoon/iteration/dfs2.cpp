//
// Created by LEE GUNHO on 2023/03/29.
//

// 알고리즘 수업 - 깊이 우선 탐색 2 : https://www.acmicpc.net/problem/24480

/*
 * dfs 만드는데 인접 정점을 내림차순으로 정렬
 */

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int V,E,R;

const int SIZE = 100000 + 1;
vector<int> v[SIZE];
int visited[SIZE];

int cnt = 1;
int result[SIZE];

void dfs(int s)
{
    if ( visited[s] )
        return;

    visited[s] = true;
    result[s] = cnt++;

    for(int n=0;n<v[s].size();n++)
    {
        dfs(v[s][n]);
    }
}

int main()
{
    cin >> V >> E >> R; // 뭘 루프로 추가로 받아야 되는지 입력값 주의!!

    // input
    for(int k=0;k<E;k++)
    {
        int src,dst;
        cin >> src >> dst;

        // bidirection
        v[src].push_back(dst);
        v[dst].push_back(src);
    }

    // sort 내림차순
    for(int k=1;k<=V;k++)
    {
        sort(v[k].begin(), v[k].end(), greater<int>());
    }

    //fill_n(visited, SIZE, 0);

    // dfs
    dfs(R);

    // output
    for(int k=1;k<=V;k++)
    {
        cout << result[k] << "\n";
    }
}
