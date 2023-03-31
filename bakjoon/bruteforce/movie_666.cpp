//
// Created by LEE GUNHO on 2023/03/31.
//

// 영화감독 숌 : https://www.acmicpc.net/problem/1436

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int k;
    cin >> k;

    int cnt = 0;
    for(int n=0;n<10000000;n++)
    {
        string s = to_string(n);

        if ( string::npos != s.find("666") )
        {
            if ( ++cnt == k )
            {
                cout << n;
                break;
            }
        }
    }
    return 0;
}
