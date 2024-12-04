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

bool isValid(string &s)
{
    ll b = true;
    rep(i,0,sz(s))
    {
        if (!isdigit(s[i]) && s[i] != ',')
            return false;
        if (s[i] == ',' && !b)
            return false;
        if (s[i] == ',')
            b = false;
    }
    return true;
}

ll mul(string &s, bool b)
{
    ll a = stol(s.substr(0, s.find(','))), c = stol(s.substr(s.find(',')+1));
    if (!b)
        a = 0;
    return a*c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll ret = 0;
    string str, tmp;
    getline(cin, str, '\0');
    size_t i = 0, j = 0, e = 0;
    map<int,string> m;
    m.ins({0, "do()"});
    while (true)
    {
        i = str.find("mul", i);
        if (i == str.npos)
            break;
        i += 3;
        if (str[i] != '(')
            continue;
        e = str.fof(')', i);
        if (e == str.npos)
            continue;
        i++;
        tmp = str.substr(i, e-i);
        if (!isValid(tmp))
            continue;
        m.ins({i,tmp});
    }
    i = 0, j = 0;
    while (true)
    {
        i = str.find("don't()", i);
        j = str.find("do()", j);
        if (i != str.npos)
            m.ins({i, str.substr(i,7)}), i++;
        if (j != str.npos)
            m.ins({j, str.substr(j,4)}), j++;
        if (i == str.npos && j == str.npos)
            break;
    }
    bool b = true;
    for (auto it = bg(m); it != ed(m); it++)
    {
        if (it->sc == "don't()")
        {
            b = false;
            continue;
        }
        else if (it->sc == "do()")
        {
            b = true;
            continue;
        }
        ret += mul(it->sc, b);
    }
    cout << ret << endl;
    return 0;
}