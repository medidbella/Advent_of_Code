//MTRX

#include <iostream>
#include <sstream>
#include <string>

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

long long mul(string &s)
{
    long long a = stol(s.substr(0, s.find(','))), b = stol(s.substr(s.find(',')+1));
    return a*b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long ret = 0;
    string str, tmp;
    getline(cin, str, '\0');
    size_t i = 0, b = 0, e = 0;
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
        ret += mul(tmp);
    }
    cout << ret << endl;
    return 0;
}