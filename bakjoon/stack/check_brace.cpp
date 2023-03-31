//
// Created by LEE GUNHO on 2023/03/31.
//

// 균형잡힌 세상 : https://www.acmicpc.net/problem/4949

// ([)]).
// no!

#include <iostream>
#include <stack>

using namespace std;

bool checkBrace(string s)
{
    stack<char> st;

    for(char c: s)
    {
        if ( c == '(' || c == '[' )
        {
            st.push(c);
            continue;
        }

        if ( c == ')' )
        {
            if ( !st.empty() && '(' == st.top() )
            {
                st.pop();
                continue;
            }
            return false;
        }

        if ( c == ']' )
        {
            if ( !st.empty() && '[' == st.top() )
            {
                st.pop();
                continue;
            }
            return false;
        }
    }

    return st.empty();
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    while(true)
    {
        string s;
        getline(cin, s);

        if ( "." == s )
        {
//            cout << "yes";    // 10% 에러 나는건 . 일때 출력 안함 ㅡㅡ;
            break;
        }
        cout << (checkBrace(s) ? "yes" : "no") << "\n";
    }
    return 0;
}
