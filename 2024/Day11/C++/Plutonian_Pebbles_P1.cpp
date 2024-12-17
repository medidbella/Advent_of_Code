//MTRX

#include <iostream>
#include <sstream>
#include <string>
#include <list>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    list<pair<long long, string>> ls;
    long long a;

    getline(cin, str);
    stringstream ss(str);
    while(ss >> a)
        ls.push_back({a,to_string(a)});
    a = 25;
    while (a--)
    {
        auto it = ls.begin();
        while (it != ls.end())
        {
            bool b = true;
            if (it->first == 0)
            {
                it->first++;
                it->second = "1";
            }
            else if (it->second.size() % 2 == 0)
            {
                b = false;
                string s1 = it->second.substr(0, (it->second.size()/2));
                string s2 = it->second.substr(it->second.size()/2);
                it->first = stol(s1), it->second = s1;
                ls.insert(++it, {stol(s2), to_string(stol(s2))});
            }
            else
            {
                it->first *= 2024;
                it->second = to_string(it->first);
            }
            if (b)
                it++;
        }
    }
    cout << ls.size() << endl;
    return 0;
}