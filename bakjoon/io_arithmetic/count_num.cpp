//
// Created by LEE GUNHO on 2023/03/21.
//

// https://www.acmicpc.net/problem/10807
// 개수 세기

#include <iostream>
using namespace std;

int main()
{
    int count=0, numbers[100] ={0,};
    cin >> count;
    for(int n=0;n<count;n++)
    {
        cin >> numbers[n];
    }

    int num = 0, found=0;
    cin >> num;
    for(int n=0;n<count;n++)
    {
        if ( num == numbers[n] )
            found++;
    }

    cout << found;
    return 0;
}
