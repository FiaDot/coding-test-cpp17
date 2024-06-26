//
// Created by LEE GUNHO on 2023/03/24.
//

// 덱 : https://www.acmicpc.net/problem/10866

/*
정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여덟 가지이다.

push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 */
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int count;
    cin >> count;

    deque<int> dq;

    for(int n=0;n<count;n++)
    {
        string cmd;
        cin >> cmd;

        int v;
        if ( cmd == "push_front" )
        {
            cin >> v;
            dq.push_front(v);
            continue;
        }

        if ( cmd == "push_back" )
        {
            cin >> v;
            dq.push_back(v);
            continue;
        }

        if ( cmd == "pop_front" )
        {
            v = -1;

            if ( !dq.empty() )
            {
                v = dq.front();
                dq.pop_front();
            }
        }

        if ( cmd == "pop_back" )
        {
            v = -1;

            if ( !dq.empty() )
            {
                v = dq.back();
                dq.pop_back();
            }
        }

        if ( cmd == "size" )
            v = dq.size();

        if ( cmd == "empty" )
            v = dq.empty() ? 1 : 0;


        if ( cmd == "front" )
        {
            v = -1;

            if ( !dq.empty() )
                v = dq.front();
        }

        if ( cmd == "back" )
        {
            v = -1;

            if ( !dq.empty() )
                v = dq.back();
        }

        cout << v << '\n';
    }

    return 0;
}
