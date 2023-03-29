//
// Created by LEE GUNHO on 2023/03/29.
//

// 알고리즘 수업 - 깊이 우선 탐색 1 : https://www.acmicpc.net/problem/24479

/*
첫째 줄에 정점의 수 N (5 ≤ N ≤ 100,000),
간선의 수 M (1 ≤ M ≤ 200,000),
시작 정점 R (1 ≤ R ≤ N)이 주어진다.

다음 M개 줄에 간선 정보 u v가 주어지며 정점 u와 정점 v의 가중치 1인 양방향 간선을 나타낸다. (1 ≤ u < v ≤ N, u ≠ v) 모든 간선의 (u, v) 쌍의 값은 서로 다르다.

 */


/*
테스트
5 5 1
1 4
1 2
2 3
2 4
3 4

결과
1
2
3
4
0
 */


/*
 반례

6 4 1
2 3
1 4
1 5
4 6

정답
1
0
0
2
4
3
*/

#include <iostream>
#include <vector>
#include <algorithm> //sort
using namespace std;

const int VERTEX_SIZE = 100001;
vector<int> v[VERTEX_SIZE];
int visited[VERTEX_SIZE];
int N, M, R;

int result[VERTEX_SIZE];
int cnt = 1;

void dfs(int p)
{
    if ( visited[p] )
        return;

    // 문제 이해!!! 시작 정점에서 방문할 수 없는 경우 0을 출력한다.
    result[p] = cnt++; // 현재 지점에 순서를 적어줌
    visited[p] = true;
    // 일반적으로 출력!

    for(int n=0;n<v[p].size(); n++)
    {
        dfs(v[p][n]);
    }
}

int main()
{
    cin >> N >> M >> R;

    for(int m=1;m<=M;m++)
    {
        int src,dst;
        cin >> src >> dst;

        v[src].push_back(dst);
        // 양방형을 위해
        v[dst].push_back(src);
    }

    // sort 오름차순
    for(int n=1;n<=N;n++)
    {
        sort(v[n].begin(), v[n].end());
    }

    fill_n(visited, VERTEX_SIZE, 0);
    dfs(R);

    for(int n=1;n<=N;n++)
    {
        cout << result[n] << "\n";
    }

    return 0;
}
