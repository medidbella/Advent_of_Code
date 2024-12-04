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
        bool b = false;
        c = 1;
        if (v[0] > v[1])
            b = true;
        for(int i = 1; i < v.size(); i++)
        {
            b ? a = v[i-1] - v[i] : a = v[i] - v[i-1];
            if (a > 3 || a < 1)
            {
                c = 0;
                break;
            }
        }
        ret += c;
    }
    cout << ret << endl;
    return 0;
}