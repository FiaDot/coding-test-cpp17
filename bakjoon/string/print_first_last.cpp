//
// Created by LEE GUNHO on 2023/03/22.
//

// 문자..열 : https://www.acmicpc.net/problem/9086
// 첫 글자, 마지막 글자.


#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int c;
    cin >> c;

    vector<string> v;

    for(int n=0;n<c;n++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }

    for(int n=0;n<c;n++)
    {
        string s = v[n];
        cout << s[0] << s[s.length()-1] << endl;
    }
    return 0;
}
