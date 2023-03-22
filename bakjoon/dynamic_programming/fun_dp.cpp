//
// Created by LEE GUNHO on 2023/03/22.
//

// 신나는 함수 실행 : https://www.acmicpc.net/problem/9184

/*
w(a,b,c)

if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
w(20, 20, 20)

if a < b and b < c, then w(a, b, c) returns:
w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

otherwise it returns:
w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

*/

// 입력은 세 정수 a, b, c로 이루어져 있으며, 한 줄에 하나씩 주어진다. 입력의 마지막은 -1 -1 -1로 나타내며, 세 정수가 모두 -1인 경우는 입력의 마지막을 제외하면 없다.

// 입력으로 주어진 각각의 a, b, c에 대해서, w(a, b, c)를 출력한다.


// -50 ≤ a, b, c ≤ 50

// original
//int w(int a, int b, int c)
//{
//    if ( a <= 0 || b <= 0 || c <= 0 )
//        return 1;
//
//    if ( a > 20 || b > 20 || c > 20 )
//        return w(20,20,20);
//
//    if ( a < b && b < c )
//        return w(a,b,c-1) + w(a, b-1, c-1) - w(a,b-1,c);
//
//    return w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
//}



#include <iostream>
using namespace std;

int cache[21][21][21];

int w2(int a, int b, int c)
{
    if ( a <= 0 || b <= 0 || c <= 0 )
        return 1;

    if ( a > 20 || b > 20 || c > 20 )
        return w2(20,20,20);

    if ( a < b && b < c )
    {
        if ( 0 == cache[a][b][c] )
            cache[a][b][c] = w2(a,b,c-1) + w2(a, b-1, c-1) - w2(a,b-1,c);
        return cache[a][b][c];
    }

    if ( 0 == cache[a][b][c] )
        cache[a][b][c] = w2(a-1, b, c) + w2(a-1, b-1, c) + w2(a-1, b, c-1) - w2(a-1, b-1, c-1);
    return cache[a][b][c];
}

int main()
{
    int a,b,c;

    while(true)
    {
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
            break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w2(a,b,c) << endl;
    }

    return 0;
}