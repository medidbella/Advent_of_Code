//MTRX

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int H = 0, W, RET = 0;

void fun(int p, int x, int y, vector<string> &v, vector<vector<bool>> &vis)
{
    int c;
    if (x < 0 || x >= H || y < 0 || y >= W || vis[x][y] || !isdigit(v[x][y]))
        return;
    c = v[x][y] - 48;
    if (c - 1 != p)
        return;
    if (c == 9)
    {
        RET++;
        return;
    }
    vis[x][y] = true;
    fun(c, x+1, y, v, vis);
    fun(c, x-1, y, v, vis);
    fun(c, x, y+1, v, vis);
    fun(c, x, y-1, v, vis);
    vis[x][y] = false;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    vector<string> v;
    vector<vector<bool>> vis;
    set<pair<int,int>> se, score;

    while (getline(cin, str))
    {
        W = str.size();
        for (int i = 0; i < W; i++)
            if (str[i] == '0')
                se.insert({H,i});
        v.push_back(str);
        H++;
    }
    for (auto it = se.begin(); it != se.end(); it++)
    {
        score = set<pair<int,int>>();
        vis = vector<vector<bool>>(H, vector<bool>(W, false));
        fun(-1, it->first, it->second, v, vis);
    }
    cout << RET << endl;
    return 0;
}