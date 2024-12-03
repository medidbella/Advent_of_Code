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

    mset<ll>left, right;
    string str;
    ll ret = 0;
    while (getline(cin, str))
    {
        stringstream s(str);
        ll l, r;
        s >> l, s >> r;
        left.ins(l);
        right.ins(r);
    }
    for(auto it = bg(left), jt = bg(right); it != ed(left); it++, jt++)
        ret += abs(*it - *jt);
    cout << ret << endl;
    return 0;
}