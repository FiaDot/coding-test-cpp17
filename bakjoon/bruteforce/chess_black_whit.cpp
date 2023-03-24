//
// Created by LEE GUNHO on 2023/03/24.
//


// 체스판 다시 칠하기 : https://www.acmicpc.net/problem/1018

#include <iostream>
#include <vector>

using namespace std;

vector<string> a;

string w[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
};

string b[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
};


int counter_w(int sx, int sy)
{
    int cnt = 0;
    for (int cy = 0; cy < 8; cy++)
    {
        for (int cx = 0; cx < 8; cx++)
        {
            // 행렬 구조 다름 ㅡㅡ;
            if ( a[sx+cy][sy+cx] != w[cy][cx] )
                cnt++;
        }
    }
    return cnt;
}

int counter_b(int sx, int sy)
{
    int cnt = 0;
    for (int cy = 0; cy < 8; cy++)
    {
        for (int cx = 0; cx < 8; cx++)
        {
            if ( a[sx+cy][sy+cx] != b[cy][cx] )
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    int x,y;
    cin >> y >> x;

    for(int sy=0;sy<y;sy++) {
        string s;
        cin >> s;
        a.push_back(s);
    }

    int m = 99999;

    for(int sy=0;sy <= y - 8;sy++)
    {
        for(int sx=0;sx <= x - 8 ;sx++)
        {
            int w = counter_w(sy, sx);
            int b = counter_b(sy, sx);

            m = min(m, min(w,b));
        }
    }

    cout << m;
    return 0;
}

