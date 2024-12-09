//MTRX

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

long long fun(vector<long long> &v, int i, long long val)
{
    if (i == v.size() || val > v[0])
        return val;
    long long ret = fun(v, i + 1, val + v[i]);
    if (ret == v[0])
        return ret;
    return fun(v, i + 1, val * v[i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, s;
    long long ret = 0, r;

    while (getline(cin, str))
    {
        vector<long long> v;
        stringstream ss(str);
        while (ss >> s)
            v.push_back(stol(s));
        r = fun(v, 2, v[1]);
        if (r == v[0])
            ret += r;
    }
    cout << ret << endl;
    return 0;
}