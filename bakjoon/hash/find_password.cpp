//
// Created by LEE GUNHO on 2023/04/12.
//

// 비밀번호 찾기 : https://www.acmicpc.net/problem/17219

/*
16 4
noj.am IU
acmicpc.net UAENA
startlink.io THEKINGOD
google.com ZEZE
nate.com VOICEMAIL
naver.com REDQUEEN
daum.net MODERNTIMES
utube.com BLACKOUT
zum.com LASTFANTASY
dreamwiz.com RAINDROP
hanyang.ac.kr SOMEDAY
dhlottery.co.kr BOO
duksoo.hs.kr HAVANA
hanyang-u.ms.kr OBLIVIATE
yd.es.kr LOVEATTACK
mcc.hanyang.ac.kr ADREAMER
startlink.io
acmicpc.net
noj.am
mcc.hanyang.ac.kr
 */

#include <iostream>
#include <map>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    map<string, string> m;

    for(int n=0;n<N;n++)
    {
        string s, pwd;
        cin >> s >> pwd;

        m.insert({s, pwd});
    }

    for(int n=0;n<M;n++)
    {
        string s;
        cin >> s;

        auto k = m.find(s);

        if ( k != m.end() )
            cout << k->second << "\n";
    }
    return 0;
}
