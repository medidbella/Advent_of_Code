//MTRX

#include <iostream>
#include <sstream>
#include <string>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    multiset<int>left, right;
    string str;
    long long ret = 0;
    while (getline(cin, str))
    {
        stringstream s(str);
        long long l, r;
        s >> l, s >> r;
        left.insert(l);
        right.insert(r);
    }
    for(auto lit = left.begin(), rit = right.begin(); lit != left.end(); lit++, rit++)
        ret += abs(*lit - *rit);
    cout << ret << endl;
    return 0;
}