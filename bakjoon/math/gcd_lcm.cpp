//
// Created by LEE GUNHO on 2023/03/23.
//

// 최대공약수와 최소공배수 : https://www.acmicpc.net/problem/2609

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b, int gcdValue)
{
    return a * b / gcdValue;
}
int main()
{
    int a,b;
    cin >> a >> b;

    int g = gcd(a,b);
    cout << g << endl;
    cout << lcm(a,b,g);
    return 0;
}