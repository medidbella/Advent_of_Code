#include <bits/stdc++.h>

using namespace std;

int main() {
    int pos = 50;
    long long count = 0;
    string s;
    while (cin >> s) {
        int n = stoi(s.substr(1));
        if (s[0] == 'L') {
            for (int i = 1; i <= n; i++) {
                pos = (pos - 1 + 100) % 100;
                if (pos == 0)
                    count++;
            }
        } else {
            for (int i = 1; i <= n; i++) {
                pos = (pos + 1) % 100;
                if (pos == 0)
                    count++;
            }
        }
    }
    cout << count;
}
