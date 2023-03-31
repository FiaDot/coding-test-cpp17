//
// Created by LEE GUNHO on 2023/03/31.
//

// 분해합 : https://www.acmicpc.net/problem/2231

#include <iostream>
using namespace std;

int sum(int d)
{
    string s = to_string(d);

    int sum = 0;

    for(char n : s)
    {
        int v = n - '0';
        sum += v;
    }
    return d + sum;
}

int main()
{
    int n;
    cin >> n;

    for(int k=1;k<n;k++)
    {
        if ( n - sum(k) == 0 )
        {
            cout << k;
            return 0;
        }
    }

    cout << "0";
    return 0;
}