// DFS와 BFS : https://www.acmicpc.net/problem/1260

/*
4 5 1
1 2
1 3
1 4
2 4
3 4
 */

/*
1 2 4 3
1 2 3 4
 */

/*
 첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다.
 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다.
 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다.
 입력으로 주어지는 간선은 양방향이다.
*/

#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

const int TOTAL = 10001;
int visited[TOTAL];
vector<int> N[TOTAL];
int n,m,v;

void dfs(int v)
{
    visited[v] = true;
    cout << v << " ";

    // 시작점 추가
    stack<int> s;
    s.push(v);

    while(!s.empty())
    {
        // 현재 지점에서 첫번째 부터 하나씩
        int current = s.top();
        s.pop();

        for(int k=0;k<N[current].size();k++)
        {
            int next = N[current][k];
            if ( visited[next] )
                continue;

            cout << next << " ";
            visited[next] = true;

            s.push(current);
            s.push(next);

            // 최하단까지 가기 위해서 break!
            break;
        }
    }
}

void bfs(int v)
{
    visited[v] = true;
    // cout << v << " ";

    queue<int> q;
    q.push(v);

    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for(int k=0;k<N[current].size();k++)
        {
            int next = N[current][k];

            if ( visited[next] )
                continue;

            visited[next] = true;
            q.push(next);
        }
    }
}

int main()
{
    cin >> n >> m >> v;

    for(int k=0;k<m;k++)
    {
        int a,b;
        cin >> a >> b;

        N[a].push_back(b);
        N[b].push_back(a);
    }

    for (int k=0;k<=n;k++)
    {
        sort(N[k].begin(), N[k].end());
    }

    fill_n(visited, TOTAL, 0);
    dfs(v);

    cout << "\n";

    fill_n(visited, TOTAL, 0);
    bfs(v);
    return 0;
}
