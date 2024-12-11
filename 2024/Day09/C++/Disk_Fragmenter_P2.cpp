//MTRX

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

void fun(vector<int> &exp, map<int, pair<int,int>, greater<int>> &mp, set<pair<int,int>> se)
{
    while(mp.size())
    {
        pair<int,int> spr, mpr;
        auto emt = mp.end()--;
        auto st = se.begin();
        while (st->first > emt->first)
        {
            while(emt->second.first--)
                exp.push_back(emt->second.second);
            mp.erase(emt);
            emt = mp.end()--;
        }
        while (st->first < emt->first)
        {
            auto it = mp.begin();
            for(; it != emt; it++)
                if (it->second.first <= st->second)
                    break;
            mpr = {it->first, it->second.first};
            spr = {st->first+it->second.first, st->second-it->second.first};
            while (it->second.first--)
                exp.push_back(it->second.second);
            se.erase(st);
            if (spr.second)
                se.insert(spr);
            se.insert(mpr);
            st = se.begin();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    long long ret = 0, id = 0, idx = 0;
    vector<int> exp;
    map<int, pair<int,int>, greater<int>> mp;
    set<pair<int,int>> se;

    getline(cin, str);
    for(int i = 0; i < str.size(); i++)
    {
        idx += str[i] - 48;
        if (i % 2)
            se.insert({idx,str[i]-48});
        else
            mp.insert({idx,{str[i]-48,id++}});
    }
    fun(exp, mp, se);
    for(int i = 0; i < exp.size(); i++)
        ret += i * exp[i];
    cout << ret << endl;
    return 0;
}