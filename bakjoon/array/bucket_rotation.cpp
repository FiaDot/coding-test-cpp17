//
// Created by LEE GUNHO on 2023/04/10.
//

// 바구니 순서 바꾸기 : https://www.acmicpc.net/problem/10812

#include <iostream>
#include <cstring> // memcpy

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int ar[N];

    for(int n=0;n<N;n++)
        ar[n] = n+1;

    for(int n=0;n<M;n++)
    {
        int tmp[N] = {0,};

        int i,j,k;
        cin >> i >> j >> k;

        int pos = 0;
        for(int c=k-1;c<j;c++)
            tmp[pos++] = ar[c];

        for(int c=i-1;c<k;c++)
            tmp[pos++] = ar[c];

        memcpy(&ar[i-1], &tmp[0], sizeof(int)*(pos-1));
    }

    for(int n=0;n<N;n++)
        cout << ar[n] << " ";
    return 0;
}