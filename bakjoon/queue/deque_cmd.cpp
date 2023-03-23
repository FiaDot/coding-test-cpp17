//
// Created by LEE GUNHO on 2023/03/23.
//

// 큐 : https://www.acmicpc.net/problem/10845

/*
    push X: 정수 X를 큐에 넣는 연산이다.
    pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    size: 큐에 들어있는 정수의 개수를 출력한다.
    empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
    front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

    첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다.
    둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다.
    주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다.
    문제에 나와있지 않은 명령이 주어지는 경우는 없다.
*/

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    deque<int> dq;

    int count;
    cin >> count;

    for(int n=0;n<count;n++)
    {
        string cmd;
        cin >> cmd;

        int v;

        if ( cmd == "push" )
        {
            cin >> v;
            dq.push_back(v);
            continue;
        }

        if ( cmd == "pop" )
        {
            v = -1;

            if ( !dq.empty() )
            {
                v = dq.front();
                dq.pop_front();
            }
        }

        if ( cmd == "size" )
            v = (int)dq.size();

        if ( cmd == "empty")
            v = dq.empty() ? 1 : 0;

        if ( cmd == "front" )
            v = dq.empty() ? -1 : dq.front();

        if ( cmd == "back" )
            v = dq.empty() ? -1 : dq.back();

        cout << v << endl;
    }
}
