//
// Created by LEE GUNHO on 2023/03/23.
//

// 팰린드롬수 : https://www.acmicpc.net/problem/1259

#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(string s)
{
// 짝수여도 가능한가? ㅇㅇ 1111
//    const int size = (int)s.length();
//    if ( 0 == size%2 )
//        return false;

    string rev = s;
    reverse(s.begin(), s.end());

    return s == rev;

// 궂이?
//    int mid = size/2;
//    for(int n=0;n<mid;n++)
//    {
//        if ( s[n] != s[size-1-n] )
//            return false;
//    }
    return true;
}

int main()
{
    string s;
    while(cin >> s && s != "0")
        cout << (isPalindrome(s) ? "yes" : "no") << endl;
    return 0;
}
