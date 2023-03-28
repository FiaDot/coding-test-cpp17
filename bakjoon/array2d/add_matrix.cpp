//
// Created by LEE GUNHO on 2023/03/28.
//

// 행렬 덧셈 : https://www.acmicpc.net/problem/2738

#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    int a[101][101];
    int b[101][101];

    for(int cn=0;cn<n;cn++)
    {
        for(int cm=0;cm<m;cm++)
        {
            cin >> a[cn][cm];
        }
    }

    for(int cn=0;cn<n;cn++)
    {
        for(int cm=0;cm<m;cm++)
        {
            cin >> b[cn][cm];
        }
    }

    for(int cn=0;cn<n;cn++)
    {
        for(int cm=0;cm<m;cm++)
        {
            cout << a[cn][cm] + b[cn][cm];

            if ( cm < m-1 )
                cout << " ";
        }

        if ( cn < n-1 )
            cout << "\n";
    }

    return 0;
}