//
// Created by LEE GUNHO on 2023/04/04.
//

// 수 정렬하기 3 : https://www.acmicpc.net/problem/10989

#include <iostream>
// #include <vector>
// #include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int cnt;
    cin >> cnt;

// 1. 메모리 초과 (1 ≤ N ≤ 10,000,000)
//    vector<int> v(cnt, 0);
//    int num;
//    for(int n=0;n<cnt;n++)
//    {
//        cin >> num;
//        v[n] = num;
//    }
//
//    sort(v.begin(), v.end());
//
//    for(int n=0;n<cnt;n++)
//    {
//        cout << v[n] << "\n";
//    }

// 2. 단순 카운팅 (이 수는 10,000보다 작거나 같은 자연수이다.) 정렬 문제가 아님
    int nums[10001] = {0,};

    int num;
    for(int n=0;n<cnt;n++)
    {
        cin >> num;
        nums[num]++;
    }

    for(int n=1;n<10001;n++) // 결국 값의 범위는 1 ~ 10,000 이다
    {
        for(int k=0;k<nums[n];k++) // 카운트 만큼 출력하면 됨
        {
            cout << n << "\n";
        }
    }

    return 0;
}