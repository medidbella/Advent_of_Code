//MTRX

#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

bool isValid(string &s)
{
    bool b = true;
    for(int i = 0; i < s.size(); i++)
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

long long mul(string &s, bool b)
{
    long long a = stol(s.substr(0, s.find(','))), c = stol(s.substr(s.find(',')+1));
    if (!b)
        a = 0;
    return a*c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long ret = 0;
    string str, tmp;
    getline(cin, str, '\0');
    size_t i = 0, j = 0, e = 0;
    map<int,string> mp;
    mp.insert({0, "do()"});
    while (true)
    {
        i = str.find("mul", i);
        if (i == str.npos)
            break;
        i += 3;
        if (str[i] != '(')
            continue;
        e = str.find_first_of(')', i);
        if (e == str.npos)
            continue;
        i++;
        tmp = str.substr(i, e-i);
        if (!isValid(tmp))
            continue;
        mp.insert({i,tmp});
    }
    i = 0, j = 0;
    while (true)
    {
        i = str.find("don't()", i);
        j = str.find("do()", j);
        if (i != str.npos)
            mp.insert({i, str.substr(i,7)}), i++;
        if (j != str.npos)
            mp.insert({j, str.substr(j,4)}), j++;
        if (i == str.npos && j == str.npos)
            break;
    }
    bool b = true;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second == "don't()")
        {
            b = false;
            continue;
        }
        else if (it->second == "do()")
        {
            b = true;
            continue;
        }
        ret += mul(it->second, b);
    }
    cout << ret << endl;
    return 0;
}