//
// Created by LEE GUNHO on 2023/03/23.
//

// 요세푸스 문제 0 (Josephus) : https://www.acmicpc.net/problem/11866

// 쉽게 풀걸 어렵게 ... ㅡㅡ;

#include <iostream>
using namespace std;

int main()
{
    int circle, step;
    cin >> circle >> step;

    int off[circle];
    for(int n=0;n<circle;n++)
    {
        off[n] = n+1;
    }

    int count = circle;
    int pos = -1; // 초기 값 중요!

    cout << "<";
    while(count > 0)
    {
        for(int n=1;n<=step;)
        {
            pos = ++pos % circle;

            if ( -1 == off[pos] )
                continue;
            n++;
        }

        cout << off[pos];
        if ( count > 1 )
            cout << ", ";

        off[pos] = -1;
        count--;
    }
    cout << ">";
    return 0;
}
