//
// Created by LEE GUNHO on 2023/04/05.
//

// 별 찍기 - 7 : https://www.acmicpc.net/problem/2444

#include <iostream>
using namespace std;

void printStar(int n, int num)
{
    for(int space=0;space<num-n-1;space++)
    {
        cout << " ";
    }

    for(int p=0;p<n*2+1;p++)
    {
        cout << "*";
    }

    cout << "\n";
}

int main()
{
    int num;
    cin >> num;

    for(int n=0;n<num;n++)
    {
        printStar(n, num);
    }

    for(int n=num-2;n>=0;n--)
    {
        printStar(n, num);
    }

    return 0;
}