//
// Created by LEE GUNHO on 2023/03/23.
//

// 요세푸스 문제 0 (Josephus) : https://www.acmicpc.net/problem/11866

// 원래 의도가 큐 써서 하는거 ㅡㅡ;

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int circle, step;
    cin >> circle >> step;

    deque<int> d;
    for(int n=1;n<=circle;n++)
        d.push_back(n);

    cout << "<";
    while(!d.empty())
    {
        for(int k=1;k<step;k++)
        {
            d.push_back(d.front());
            d.pop_front();
        }

        cout << d.front();
        d.pop_front();

        if (d.size() > 0)
            cout << ", ";
    }
    cout << ">";
    return 0;
}