//MTRX

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

void fun(map<int, pair<bool,pair<int,int>>, greater<int>> &mp, set<pair<int,int>> &se)
{
    set<int, greater<int>> keys;
    pair<int,int>pr;
    for (auto it = mp.begin(); it != mp.end(); it++)
        keys.insert(it->first);
    int key = *keys.begin();
    for (auto it = mp.find(key); it != mp.end();)
    {
        bool b = false;
        if (it->second.first)
        {
            it++;
            continue;
        }
        for (auto jt = se.begin(); jt->first < it->first; jt++)
        {
            if (jt->second >= it->second.second.first)
            {
                b = true;
                pr = {jt->first + it->second.second.first, jt->second-it->second.second.first};
                mp.insert({jt->first,{true,it->second.second}});
                se.insert(pr);
                se.erase(jt);
                se.insert({it->first, it->second.second.first});
                break;
            }
        }
        if (!b)
            it->second.first = true;
        else
            mp.erase(it);
        keys.erase(keys.begin());
        key = *keys.begin();
        it = mp.find(key);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    long long ret = 0, id = 0, idx = 0;
    map<int, pair<bool,pair<int,int>>, greater<int>> mp;
    set<pair<int,int>> se;

    getline(cin, str);
    for(int i = 0; i < str.size(); i++)
    {
        if (i % 2)
            se.insert({idx,str[i]-48});
        else
            mp.insert({idx,{false,{str[i]-48,id++}}});
        idx += str[i] - 48;
    }
    fun(mp, se);
    idx = 0;
    auto st = se.begin();
    for (auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        while (st->first < it->first)
        {
            id = st->second;
            while (id--)
                idx++;
            se.erase(st);
            st = se.begin();
        }
        id = it->second.second.first;
        while (id--)
        {
            ret += it->second.second.second * idx;
            idx++;
        }   
    }
    cout << ret << endl;
    return 0;
}