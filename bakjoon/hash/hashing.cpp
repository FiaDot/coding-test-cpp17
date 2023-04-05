//
// Created by LEE GUNHO on 2023/04/05.
//

// Hashing : https://www.acmicpc.net/problem/15829

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int cnt;
    cin >> cnt;

    string s;
    cin >> s;

    long long total = 0;
    for(int n=0;n<cnt;n++)
    {
        total += (s[n]-'a'+1) * pow(31,n);
        total %= 1234567891;
    }

    cout << total;
    return 0;
}

