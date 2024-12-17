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

    string str;
    map<long long, long long> mp;
    long long a;

    getline(cin, str);
    stringstream ss(str);
    while(ss >> a)
        mp[a]++;
    a = 75;
    while (a--)
    {
        map<long long, long long> nmp;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            long long key = it->first, val = it->second;
            if (!key)
                nmp[1] += val;
            else if (to_string(key).size() % 2 == 0)
            {
                nmp[stol(to_string(key).substr(0, to_string(key).size()/2))] += val;
                nmp[stol(to_string(key).substr(to_string(key).size()/2))] += val;
            }
            else
                nmp[key * 2024] += val;
        }
        mp = nmp;
    }
    a = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
        a += it->second;
    cout << a << endl;
    return 0;
}