//MTRX

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long ret = 0;
    int key, value;
    string str;
    size_t f;
    map<int,set<int>> mp;
    vector<vector<int>> v;
    bool b = true;

    while (getline(cin, str))
    {
        if (str[0] == '\0')
            break;
        f = str.find("|");
        str[f] = ' ';
        stringstream ss(str);
        ss >> key >> value;
        mp[key].insert(value);
    }
    while (getline(cin, str))
    {
        vector<int> tmp;
        for(int i = 0; i < str.size(); i++)
            if (str[i] == ',')
                str[i] = ' ';
        stringstream ss(str);
        while (ss >> key)
            tmp.push_back(key);
        v.push_back(tmp);
    }
    for (int i = 0; i < v.size(); i++)
    {
        b = true;
        for (int j = v[i].size() - 2; j >= 0; j--)
        {
            key = v[i][j], value = v[i][j+1];
            auto it = mp.find(value);
            if (it == mp.end())
                continue;
            if (it->second.find(key) != it->second.end())
            {
                b = false;
                break;
            }
        }
        if (b)
            ret += v[i][(v[i].size()/2)];
    }
    cout << ret << endl;
    return 0;
}