//
// Created by LEE GUNHO on 2023/03/21.
//

// https://www.acmicpc.net/problem/25304
// 영수증

#include <iostream>
using namespace std;

int main()
{
    int expectSum, expectCount;
    cin >> expectSum;
    cin >> expectCount;

    int actualSum = 0;
    for(int n=0;n<expectCount;n++)
    {
        int itemPrice, itemCount;
        cin >> itemPrice >> itemCount;

        actualSum += itemPrice * itemCount;
    }

    if ( expectSum == actualSum )
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
