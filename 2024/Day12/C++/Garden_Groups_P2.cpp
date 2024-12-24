/*
yrhiba.github.io (c). 2022-2024
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <cassert>
#include <random>
#include <sstream>
using namespace std;
# define all(x) begin(x), end(x)
# define rall(x) rbegin(x), rend(x)
typedef long long ll;

const int dir[4] {0, 0, 1, 1};
const int dr[8] {1, -1, 0, 0};
const int dc[8] {0, 0, 1, -1};

/* solution */
pair<ll, ll> operator+(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return {a.first + b.first, a.second + b.second};
}

bool checkSide(vector<vector<vector<bool>>> &side, ll i, ll j, ll o, ll k)
{
    for (ll d = 0; d < 2; d++) {
        ll ni = i + dr[k + d];
        ll nj = j + dc[k + d];
        if (ni < 0 || nj < 0 || ni >= int(side.size())
            || nj >= int(side[0].size())) continue;
        if (side[ni][nj][o])
            return (false);
    }
    return (true);
}

vector<vector<ll>> curVertSide;
vector<vector<ll>> curHorzSide;

ll rec(
    deque<string> &g, 
    vector<vector<bool>> &vis,
    ll i, ll j
)
{
    vis[i][j] = true;

    ll cur = 1;

    // Add Sides
    for (ll d = 0; d < 4; d++)
    {
        ll ni = i + dr[d];
        ll nj = j + dc[d];
        if (ni < 1 || nj < 1 || ni+1 >= int(g.size()) 
            || nj+1 >= int(g[0].size()) || g[ni][nj] != g[i][j]) {
            if (dir[d]) { 
                curVertSide.push_back({i, j, d - 2});
            } else {
                curHorzSide.push_back({i, j, d});
            }
        }
    }

    for (ll d = 0; d < 4; d++) {
        ll ni = i + dr[d];
        ll nj = j + dc[d];
        if (ni < 1 || nj < 1 || ni+1 >= int(g.size()) || nj+1 >= int(g[0].size())) continue;
        if (vis[ni][nj] || g[ni][nj] != g[i][j]) continue;
        cur += rec(g, vis, ni, nj);
    }

    return (cur);
}

void solve()
{
    deque<string> g;
    {
        string t;
        while (cin >> t) {
            t = "$" + t + "$";
            g.push_back(t);
        }
    }
    g.push_front(string(g[0].size(), '$'));
    g.push_back(string(g[0].size(), '$'));
    
    int n = int(g.size()), m = int(g[0].size());

    ll ans = 0;
    
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<vector<bool>>> horziSide(n, vector<vector<bool>>(m, vector<bool>(2, false)));
    vector<vector<vector<bool>>> vertSide(n, vector<vector<bool>>(m, vector<bool>(2, false)));
    
    for (ll i = 1; i+1 < n; i++) {
        for (ll j = 1; j+1 < m; j++) {

            if (vis[i][j]) continue;

            ll cnt = rec(g, vis, i, j), sides = 0;

            sort(all(curVertSide));
            sort(all(curHorzSide));

            for (auto &v :  curHorzSide) {
                sides += checkSide(horziSide, v[0], v[1], v[2], 2);
                horziSide[v[0]][v[1]][v[2]] = true;
            }

            for (auto &v :  curVertSide) {
                sides += checkSide(vertSide, v[0], v[1], v[2], 0);
                vertSide[v[0]][v[1]][v[2]] = true;
            }

            ans += (cnt * sides);

            for (auto &v :  curHorzSide) {
                horziSide[v[0]][v[1]][v[2]] = false;
            }
            curHorzSide.clear();
            for (auto &v :  curVertSide) {
                vertSide[v[0]][v[1]][v[2]] = false;
            }
            curVertSide.clear();
        }
    }
    
    cout << ans << '\n';
}

/* main funciton */
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return (0);
}
