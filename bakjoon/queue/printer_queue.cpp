//
// Created by LEE GUNHO on 2023/04/04.
//

// 프린터 큐 : https://www.acmicpc.net/problem/1966

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int cases;
    cin >> cases;

    for(int n=0;n<cases;n++)
    {
        int cnt, pos;
        cin >> cnt >> pos;

        deque<pair<int, bool>> q;
        for(int k=0;k<cnt;k++)
        {
            int v;
            cin >> v;
            q.push_back({v, k == pos});
        }

        int t = 0;
        while(!q.empty())
        {
            // 우선순위 높은거 탐색
            int m = q.front().first;
            for(auto it: q)
            {
                if ( m < it.first )
                {
                    m = it.first;
                    break;
                }
            }

            // 작으면 뒤로 넣기
            if ( m != q.front().first )
            {
                q.push_back(q.front());
                q.pop_front();
                continue;
            }

            t++;

            // 체크해야할 값이면 순서 출력
            if (q.front().second)
            {
                cout << t << "\n";
                break;
            }

            q.pop_front();
        }
    }
    return 0;
}