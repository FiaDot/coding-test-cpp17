//
// Created by LEE GUNHO on 2023/04/17.
//

// Z : https://www.acmicpc.net/problem/1074

#include <iostream>
#include <cmath>
using namespace std;

int N,r,c;
int ans = 0;

void checker(int y, int x, int size)
{
    if ( r == y && c == x )
    {
        cout << ans << "\n";
        return;
    }

    // 현재 사분면에 들어 있다면?
    bool isRight = r < y + size && r >= y && c < x+ size && c >= x;
    if ( isRight )
    {
        checker(y, x, size/2);
        checker(y, x+size/2, size/2);
        checker(y+size/2, x, size/2);
        checker(y+size/2, x+size/2, size/2);
    }
    else
    {
        // 안들어있으면 현재 공간은 skip
        ans += size * size;
    }
}

int main()
{
    cin >> N >> r >> c;

    int size = pow(2, N);
    checker(0, 0, size);

    return 0;
}
