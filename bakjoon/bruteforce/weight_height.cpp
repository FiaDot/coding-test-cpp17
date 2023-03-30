//
// Created by LEE GUNHO on 2023/03/30.
//

// 덩치 : https://www.acmicpc.net/problem/7568

#include <iostream>

using namespace std;

int main()
{
    int count;
    cin >> count;

    pair<int,int> a[51];

    for(int n=0;n<count;n++)
        cin >> a[n].first >> a[n].second;

    int rank=1;

    for(int n=0;n<count;n++)
    {
        for(int j=0;j<count;j++)
        {
            if ( a[n].first < a[j].first && a[n].second < a[j].second )
                rank++;
        }
        cout << rank << " ";
        rank = 1;
    }
    return 0;
}
