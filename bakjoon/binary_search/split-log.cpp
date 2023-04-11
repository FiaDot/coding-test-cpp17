//
// Created by LEE GUNHO on 2023/04/11.
//
// 나무 자르기 : https://www.acmicpc.net/problem/2805

/*
4 7
20 15 10 17

15
*/

/*
5 20
4 42 40 26 46

36
*/

/*
2 5
9 10

7 // 5아님 ㅋㅋ
*/

#include <iostream>
#include <vector>
using namespace std;

vector<long long> v;

// 2% 틀림 이유 2 : int 반환하고 있었음 ㅡㅡ;
long long cut(long long height)
{
    long long sum = 0;
    for(long long k: v)
    {
        if ( k > height )
            sum += k - height;
    }
    return sum;
}

int main()
{
    long long N,M;
    cin >> N >> M;

    long long maxv = 0;

    for(int n=0;n<N;n++)
    {
        long long h;
        cin >> h;

        if ( maxv < h )
            maxv = h;

        v.push_back(h);
    }

    // sort(v.begin(), v.end());

    long long left=0, right=maxv;
    long long mid;
    long long ans = 0;

    while(left<=right)
    {
        mid = (left + right) / 2;

//        long long sum = 0;
//        for(long long k: v)
//        {
//            if ( k > mid )
//                sum += k - mid;
//        }
        long long sum = cut(mid);
        if ( M > sum )
        {
            right = mid-1;
        }
        else//  if ( M < sum ) // 2% 틀림 이유 1 (최적해가 아니라 근사해도 필요함)
        {
            ans = mid;
            left = mid+1;
        }
    }

    cout << ans;
    return 0;
}

// 2% 틀림

