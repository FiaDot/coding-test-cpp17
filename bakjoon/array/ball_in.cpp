//
// Created by LEE GUNHO on 2023/03/21.
//

// https://www.acmicpc.net/problem/10810
// 공넣기

#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    int arr[100] = {0,}; // 초기화 주의

    for(int k=0;k<m;k++)
    {
        int begin, end, num;
        cin >> begin >> end >> num;

        for(int j=begin;j<=end;j++)
        {
            arr[j-1] = num; // 갯수가 아니라 최종 overwrite 번호
        }
    }


    for(int p=0;p<n;p++)
    {
        cout << arr[p];

        if (p < n-1)
            cout << ' ';
    }
    return 0;
}