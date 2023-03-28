//
// Created by LEE GUNHO on 2023/03/28.
//

// 최댓값 : https://www.acmicpc.net/problem/2566

#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int a[10][10];

    int m = -1;

    int px = -1;
    int py = -1;

    for(int y=0;y<9;y++)
    {
        for(int x=0;x<9;x++)
        {
            cin >> a[y][x];

            if ( m > a[y][x] )
                continue;

            m = a[y][x];
            px = x+1;
            py = y+1;
        }
    }

    cout << m << "\n";
    cout << py << " " << px;
}
