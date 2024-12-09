//MTRX

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<pair<int,int>> dir = {{-1,0} , {0,1} , {1,0}, {0,-1}};

bool fun(int x, int y, vector<string> &v, int d)
{
    int t = 0;
    if (x < 0 || x >= v.size() || y < 0 || y >= v[0].size())
        return false;
    while (t < 1e4)
    {
        x += dir[d].first, y += dir[d].second;
        if (x < 0 || x >= v.size() || y < 0 || y >= v[0].size())
            return false;
        if (v[x][y] == '#')
        {
            x -= dir[d].first, y -= dir[d].second;
            d = (d + 1) % 4;
        }
        t++;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    vector<string> v;
    int x, y, i = 0, ret = 0;

    while (getline(cin, str))
    {
        for(int j = 0; j < str.size(); j++)
            if (str[j] == '^')
                x = i, y = j;
        v.push_back(str);
        i++;
    }
    for(int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == '#')
                continue;
            v[i][j] = '#';
            ret += fun(x, y, v, 0);
            v[i][j] = '.';
        }
    }
    cout << ret << endl;
    return 0;
}