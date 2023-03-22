//
// Created by LEE GUNHO on 2023/03/22.
//

// 과제 안내신 분 : https://www.acmicpc.net/problem/5597

#include <iostream>
#include <vector>
#include <algorithm> // sort

using namespace std;

int main()
{
    vector<int> v(31, 100);
    for(int n=1;n<=30;n++)
    {
        v[n] = n;
    }

    for(int k=0;k<28;k++)
    {
        int chk = 0;
        cin >> chk;
        v[chk] = 100;
    }

    sort(v.begin(), v.end(), less<int>());

    for(int n=0;n<2;n++)
    {
        cout << v[n] << endl;
    }

    return 0;
}

