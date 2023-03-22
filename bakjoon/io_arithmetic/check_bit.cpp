//
// Created by LEE GUNHO on 2023/03/22.
//

// 검증수 : https://www.acmicpc.net/problem/2475

#include <iostream>
using namespace std;

int main()
{
    int sum = 0;

    for(int n=0;n<5;n++)
    {
        int k;
        cin >> k;
        sum += k * k;
    }

    cout << sum % 10;
    return 0;
}
