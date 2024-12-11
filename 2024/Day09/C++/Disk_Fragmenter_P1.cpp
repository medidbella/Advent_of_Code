//MTRX

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void fun(vector<pair<int,int>> &v, vector<int> &exp)
{
    int l = v.size() - 1;
    if (v[l].second == -1)
        l--;
    for (int i = 0; i < v.size(); i++)
    {
        while (v[i].first)
        {
            if (l < i)
                break;
            if (v[i].second != -1)
                exp.push_back(v[i].second);
            else if (v[l].first)
            {
                exp.push_back(v[l].second);
                v[l].first--;
            }
            else
            {
                l -= 2;
                continue;
            }
            v[i].first--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    long long ret = 0, id = 0;
    vector<pair<int,int>> v;
    vector<int> exp;

    getline(cin, str);
    for(int i = 0; i < str.size(); i++)
    {
        if (i % 2)
            v.push_back({str[i]-48,-1});
        else
            v.push_back({str[i]-48,id++});
            
    }
    fun(v, exp);
    for(int i = 0; i < exp.size(); i++)
        ret += i * exp[i];
    cout << ret << endl;
    return 0;
}