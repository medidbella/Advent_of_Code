#include <bits/stdc++.h>
using namespace std;

bool plain(long long x) {
    string s = to_string(x);
    int n = s.size();
    if (n % 2 == 0) {
        string a = s.substr(0, n/2);
        string b = s.substr(n/2);
        return a == b;
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

