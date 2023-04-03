//
// Created by LEE GUNHO on 2023/04/03.
//

// 스택 수열 : https://www.acmicpc.net/problem/1874

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int cnt;
    cin >> cnt;


    deque<int> d;
    stack<int> s;

    for(int n=0;n<cnt;n++) {
        int k;
        cin >> k;
        d.push_back(k);
    }

    int top = 0;

    vector<string> output;

    while(!d.empty())
    {
        int k = d.front();
        d.pop_front();

        while(top < k)
        {
            s.push(++top);
            // cout << "+" << "\n";
            output.push_back("+");
        }

        if ( s.empty() )
        {
            // error!
            cout << "NO" << "\n";
            return 0;
        }

        // 다 넣었으면 ㅋㅋ
        if ( k == s.top() )
        {
            // cout << "-" << "\n";
            output.push_back("-");
            s.pop();
            continue;
        }

        while(!s.empty())
        {
            if ( k == s.top() )
            {
                // cout << "-" << "\n";
                output.push_back("-");
                s.pop();
                break;
            }

            // cout << "-" << "\n";
            output.push_back("-");
            s.pop();
        }
    }

    for(auto ss: output)
    {
        cout << ss << "\n";
    }
    return 0;
}

/*
 심플하게 하는군 ;; ..... but 1632 에서 실패
  https://gaeunhan.tistory.com/16

#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main()
{
	stack<int> s;
	vector<char> result;
	int cnt = 1;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		while ( cnt <= x )
		{
			s.push(cnt);
			cnt += 1;
			result.push_back( '+' );
		}

		if (s.top() == x)
		{
			s.pop();
			result.push_back( '-' );
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << '\n'; //!< endl로 인한 시간초과 조심
	}
}

 */