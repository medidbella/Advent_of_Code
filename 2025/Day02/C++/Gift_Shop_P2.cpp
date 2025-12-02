#include <bits/stdc++.h>
using namespace std;

bool plain(long long x) {
    string s = to_string(x);
    int n = s.size();

    for (int len = 1; len <= n/2; len++)
    {
        if (n % len == 0)
        {
            string sub = s.substr(0, len);
            bool ok = (true);
            for (int i = 0; i < n; i += len)
            {
                if (s.substr(i, len) != sub)
                {
                    ok = (false);
                    break;
                }
            }
            if (ok)
                return (true);
        }
    }
    return false;
}


int main(){
    string line;
    getline(cin, line);
    long long ans = 0;

    stringstream ss(line);
    string part;
    while (getline(ss, part, ',')) {
    
        auto dash = part.find('-');
        long long L = stoll(part.substr(0, dash));
        long long R = stoll(part.substr(dash+1));
        for (long long x = L; x <= R; x++)
        {
            if (plain(x))
                ans += x;
        }
    }
    cout << ans;
}

