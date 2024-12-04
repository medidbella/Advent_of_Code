//MTRX

#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<int,int>left, right;
    string str;
    long long ret = 0;
    while (getline(cin, str))
    {
        stringstream s(str);
        long long l, r;
        s >> l, s >> r;
        left[l]++;
        right[r]++;
    }
    for(auto lit = left.begin(); lit != left.end(); lit++)
    {
        auto rit = right.find(lit->first);
        if (rit == right.end())
            continue;
        ret += (lit->first * rit->second * lit->second);
    }
    cout << ret << endl;
    return 0;
}
