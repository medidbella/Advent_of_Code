//MTRX

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<int,int>> dir = {{-1,0} , {0,1} , {1,0}, {0,-1}};
int d = 0;

int fun(int x, int y, vector<string> &v)
{
    int ret = 0;

    if (x < 0 || x >= v.size() || y < 0 || y >= v[0].size())
        return 0;
    if (v[x][y] == '#')
        return -1;
    bool b = !(v[x][y] == 'X');
    v[x][y] = 'X';
    ret = fun(x + dir[d].first, y + dir[d].second, v);
    while (ret == -1)
    {
        d = (d + 1) % 4;
        ret = fun(x + dir[d].first, y + dir[d].second, v);
    }
    return ret + b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    vector<string> v;
    size_t f;
    int x, y, i = 0;

    while (getline(cin, str))
    {
        f = str.find('^');
        if (f != str.npos)
            x = i, y = f;
        v.push_back(str);
        i++;
    }
    cout << fun(x, y, v) << endl;
    return 0;
}