//MTRX

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

long long fun(map<int, pair<int,int>, greater<int>> &mp, map<int, set<int>> &se)
{
    long long ret = 0;

    while (mp.size())
    {
        int idx = 1e9;
        auto it = mp.begin();
        auto jt = se.begin();
        for (auto kt = jt, nkt = kt; kt != se.end(); nkt++, kt = nkt)
        {
            if (!kt->second.size())
                se.erase(kt);
            else if (kt->first >= it->second.first && *kt->second.begin() < idx && *kt->second.begin() < it->first)
                idx = *kt->second.begin(), jt = kt;
        }
        if (idx != 1e9)
        {
            jt->second.erase(jt->second.begin());
            se[jt->first - it->second.first].insert(idx + it->second.first);
            for (int i = 0; i < it->second.first; i++)
                ret += it->second.second * (idx + i);
        }
        else
            for (int i = 0; i < it->second.first; i++)
                ret += it->second.second * (it->first + i);
        mp.erase(it);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    long long ret = 0, id = 0, idx = 0;
    map<int, pair<int,int>, greater<int>> mp;
    map<int, set<int>> se;

    getline(cin, str);
    for(int i = 0; i < str.size(); i++)
    {
        if (str[i] - 48)
        {
            if (i % 2)
                se[str[i]-48].insert(idx);
            else
                mp.insert({idx,{str[i]-48,id++}});
        }
        idx += str[i] - 48;
    }
    cout << fun(mp, se) << endl;
    return 0;
}