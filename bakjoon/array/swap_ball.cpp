//
// Created by LEE GUNHO on 2023/03/22.
//


// https://www.acmicpc.net/problem/10813
// 공 바꾸기

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> v(n+1);
    for(int k=0;k<n+1;k++)
    {
        v[k] = k;
    }

    for(int k=0;k<m;k++)
    {
        int i,j;
        cin >> i >> j;
        swap(v[i], v[j]);
    }

    for(int k=1;k<=n;k++)
    {
        cout << v[k];

        if ( k < n )
            cout << ' ';
    }
    return 0;
}
