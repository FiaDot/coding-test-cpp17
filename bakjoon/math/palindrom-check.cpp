//
// Created by LEE GUNHO on 2023/04/07.
//

// 팰린드롬인지 확인하기 : https://www.acmicpc.net/problem/10988

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    string s2 = s;
    reverse(s2.begin(), s2.end());

    cout << (s == s2) ? 1 : 0;
    return 0;
}
