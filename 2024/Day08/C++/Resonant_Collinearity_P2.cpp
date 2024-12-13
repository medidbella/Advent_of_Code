//MTRX

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

void    fun(set<pair<int,int>> &se, set<pair<int,int>> &ret, int W, int H)
{
    for (auto it = se.begin(); it != se.end(); it++)
    {
        ret.insert({it->first,it->second});
        for (auto jt = se.begin(); jt != se.end(); jt++)
        {
            if (it == jt)
                continue;
            pair<pair<int,int>,pair<int,int>> pr = {{jt->first,jt->second},{-1,-1}};
            pr.second.first = abs(it->first - jt->first)  * ((it->first < jt->first) ? 1 : -1);
            pr.second.second = abs(it->second - jt->second) * ((it->second < jt->second) ? 1 : -1);
            while (true)
            {
                int x = pr.first.first + pr.second.first;
                int y = pr.first.second + pr.second.second;
                if (x < 0 || x >= H || y < 0 || y >= W)
                    break;
                ret.insert({x,y});
                pr.first = {x,y};
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    map<char,set<pair<int,int>>> mp;
    set<pair<int,int>> se;
    int ret = 0, W = 0, H = 0;

    while (getline(cin, str))
    {
        W = str.size();
        for(int i = 0; i < W; i++)
        {
            if (str[i] == '.')
                continue;
            mp[str[i]].insert({H,i});
        }
        H++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
        fun(it->second, se, W, H);
    cout << se.size() << endl;
    return 0;
}