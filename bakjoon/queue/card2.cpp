//
// Created by LEE GUNHO on 2023/03/24.
//

// 카드2 : https://www.acmicpc.net/problem/2164

#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int cnt;
    cin >> cnt;

    deque<int> d;
    for(int n=0;n<cnt;n++)
    {
        d.push_back(n+1);
    }

    while(d.size() != 1)
    {
        d.pop_front();
        d.push_back(d.front());
        d.pop_front();
    }

    cout << d.front();
    return 0;
}