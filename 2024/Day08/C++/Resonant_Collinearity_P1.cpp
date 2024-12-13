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
        for (auto jt = se.begin(); jt != se.end(); jt++)
        {
            if (it == jt)
                continue;
            int x = jt->first + (abs(it->first - jt->first)  * ((it->first < jt->first) ? 1 : -1));
            int y = jt->second + (abs(it->second - jt->second) * ((it->second < jt->second) ? 1 : -1));
            if (x < 0 || x >= H || y < 0 || y >= W)
                continue;
            ret.insert({x,y});
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