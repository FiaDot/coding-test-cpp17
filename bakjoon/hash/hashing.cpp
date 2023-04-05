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
//  cnt 50 이하 성공
//    for(int n=0;n<cnt;n++)
//    {
//        total += (s[n]-'a'+1) * pow(31,n);
//        total %= 1234567891;
//    }


//  cnt 50까지 성공
    const long m = 1234567891;
    long long r = 1;
    for(int n=0;n<cnt;n++)
    {
        total += (s[n]-'a'+1) * r;
        total %= m;
        // r을 pow를 쓰게 되면 overflow 발생. 매번 제곱하게 되니 그냥 곱하고 modulation
        r = (r * 31) % m;
    }

    cout << total;
    return 0;
}

