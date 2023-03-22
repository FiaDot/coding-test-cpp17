//
// Created by LEE GUNHO on 2023/03/22.
//

// 바구니 뒤집기 : https://www.acmicpc.net/problem/10811
// i ~ j 까지를 reverse 하는게 핵심

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int bucket, order;
    cin >> bucket >> order;

    vector<int> v;
    for(int n=0;n<bucket;n++)
    {
        v.push_back(n+1);
    }

    for(int n=0;n<order;n++)
    {
        int i,j;
        cin >> i >> j;

        i--;
        j--;
        vector<int> rev;

        for(int c=j;c>=i;c--)
        {
            rev.push_back(v[c]);
        }

        for(int c=i;c<=j;c++)
        {
            v[c] = rev[c-i];
        }
    }

    for(int n=0;n<bucket;n++)
    {
        cout << v[n];

        if ( n < bucket - 1)
            cout << ' ';
    }

    return 0;
}