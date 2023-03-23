//
// Created by LEE GUNHO on 2023/03/23.
//

// 나이순 정렬 : https://www.acmicpc.net/problem/10814
// 괜히 어렵게 풀음 stable_sort !

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct Member
{
    int age;
    int seq;
    string name;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    set<int> s;
    map<int, vector<Member>*> m;

    for(int n=0;n<count;n++)
    {
        int age;
        string name;
        cin >> age >> name;

        auto item = m.find(age);
        if (item != m.end()) {
            item->second->push_back({age, n, name});
        } else {
            vector<Member>* mm = new vector<Member>();
            mm->push_back({age, n, name});
            m.insert({age, mm});
            s.insert(age);
        }
    }

    for(auto key : s) {
        vector<Member>* v = m.find(key)->second;
        sort(v->begin(), v->end(), [] (const Member& a, const Member& b) {
            return  a.seq < b.seq;
        });

        for(auto mem: *v)
        {
            cout << mem.age << " " << mem.name << '\n';
        }
    }

    return 0;
}
