//MTRX

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long ret = 0, a, c = 1;
    string str;
    while (getline(cin, str))
    {
        vector<int> v;
        stringstream s(str);
        while (s >> a)
            v.push_back(a);
        for(int i = 0; i < v.size(); i++)
        {
            bool b = false;
            c = 1;
            vector<int>t;
            for(int j = 0; j < v.size(); j++)
            {
                if (i == j)
                    continue;
                t.push_back(v[j]);
            }
            if (t[0] > t[1])
                b = true;
            for(int j = 1; j < t.size(); j++)
            {
                b ? a = t[j-1] - t[j] : a = t[j] - t[j-1];
                if (a > 3 || a < 1)
                {
                    c = 0;
                    break;
                }
            }
            if (c)
                break;
        }
        ret += c;
    }
    cout << ret << endl;
    return 0;
}