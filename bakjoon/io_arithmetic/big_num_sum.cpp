//
// Created by LEE GUNHO on 2023/03/21.
//

// https://www.acmicpc.net/problem/11382
// 큰 수 A+B+C 더하기

#include <iostream>

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    long long int a,b,c,sum;
    std::cin >> a >> b >> c;
    sum = a+b+c;
    std::cout << sum;
    return 0;
}

