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
const int dr[8] {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[8] {0, 1, 0, -1, 1, -1, -1, 1};

/* solution */
pair<ll, ll> operator+(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return {a.first + b.first, a.second + b.second};
}

pair<ll, ll> rec(vector<string> &g, vector<vector<bool>> &vis, ll i, ll j)
{
    vis[i][j] = true;

    pair<ll, ll> cur = {1, 0};

    for (ll d = 0; d < 4; d++) {
        ll ni = i + dr[d];
        ll nj = j + dc[d];
        if (ni < 0 || nj < 0 || ni >= int(g.size()) 
            || nj >= int(g[0].size()) || g[ni][nj] != g[i][j]) {
            cur.second += 1;
        }
    }

    for (ll d = 0; d < 4; d++) {
        ll ni = i + dr[d];
        ll nj = j + dc[d];
        if (ni < 0 || nj < 0 || ni >= int(g.size()) || nj >= int(g[0].size())) continue;
        if (vis[ni][nj] || g[ni][nj] != g[i][j]) continue;
        cur = cur + rec(g, vis, ni, nj);
    }

    return (cur);
}

void solve()
{
    vector<string> g;
    {
        string t;
        while (cin >> t) {
            g.push_back(t);
        }
    }
    assert(g.empty() == false && "empty graph");
    int n = int(g.size()), m = int(g[0].size());
    ll ans = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            pair<ll, ll> q = rec(g, vis, i, j);
            ans += (q.first * q.second);
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
