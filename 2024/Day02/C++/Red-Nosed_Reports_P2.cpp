//MTRX

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl '\n'
#define sp ' '
#define vec vector
#define mmap multimap
#define mset multiset
#define pr pair
#define mp make_pair
#define fr first
#define sc second
#define ins insert
#define pf push_front
#define pb push_back
#define er erase
#define sz(x) int(x.size())
#define bg(x) x.begin()
#define ed(x) x.end()
#define rbg(x) x.rbegin()
#define all(x) bg(x),x.end()
#define rall(x) rbg(x),x.rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define fof find_first_of
#define lof find_last_of
#define py cout<<"YES\n";
#define pn cout<<"NO\n";
#define p1 cout<<"-1\n";
#define debug(x) cerr<<">>>>>>>>>>>> : "<<x<<endl;
#define re(t) while(t--)
#define rep(i,m,n) for(int i=m;i<n;i++)
#define rrep(i,m,n) for(int i=n;i>=m;i--)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll ret = 0, a, c = 1;
    string str;
    while (getline(cin, str))
    {
        vec<ll> v;
        stringstream s(str);
        while (s >> a)
            v.pb(a);
        rep(i,0,sz(v))
        {
            bool b = false;
            c = 1;
            vec<ll>t;
            rep(j,0,sz(v))
            {
                if (i == j)
                    continue;
                t.pb(v[j]);
            }
            if (t[0] > t[1])
                b = true;
            rep(j,1,sz(t))
            {
                b ? a = t[j-1] - t[j] : a = t[j] - t[j-1];
                if (a > 3 || a < 1)
                {
                    c = 0;
                    break;
                }
            }
            if (c)
                break;
        }
        ret += c;
    }
    cout << ret << endl;
    return 0;
}