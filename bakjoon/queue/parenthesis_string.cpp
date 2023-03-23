//
// Created by LEE GUNHO on 2023/03/23.
//

// 괄호 : https://www.acmicpc.net/problem/9012

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int count;
    cin >> count;

    for(int n=0;n<count;n++)
    {
        string s;
        cin >> s;

        stack<int> st;
        for(int k=0;k<s.length();k++)
        {
            if ( s[k] == '(' )
                st.push(1);
            else if ( s[k] == ')' )
            {
                if ( st.empty() )
                {
                    st.push(0);
                    break;
                }

                st.pop();
            }
        }

        cout << (st.empty() ? "YES" : "NO") << '\n';
    }
    return 0;
}