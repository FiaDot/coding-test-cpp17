//
// Created by LEE GUNHO on 2023/03/21.
//

// https://www.acmicpc.net/problem/25314
// long long int
#include <iostream>

using namespace std;

int main()
{
    int length;
    cin >> length;

    for(int n=0;n<length/4;n++)
    {
        cout << "long ";
    }

    cout << "int";
    return 0;
}