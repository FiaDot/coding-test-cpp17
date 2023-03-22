//
// Created by LEE GUNHO on 2023/03/22.
//

// 제로 : https://www.acmicpc.net/problem/10773
// 스택 사용 문제

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int c;
    cin >> c;

    stack<int> s;

    for(int n=0;n<c;n++)
    {
        int k;
        cin >> k;

        if ( 0 == k )
        {
            s.pop();
            continue;
        }

        s.push(k);
    }

    int sum = 0;

    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }

    cout << sum;
    return 0;
}
