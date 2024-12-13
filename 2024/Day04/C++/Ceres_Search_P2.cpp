//MTRX

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int x_sam(vector<string> &v)
{
    int ret = 0;
    for(int i = 1; i < v.size() - 1; i++)
    {
        for (int j = 1; j < v[i].size() - 1; j++)
        {
            if (v[i][j] == 'A')
            {
                if ((v[i-1][j-1] == 'M' && v[i+1][j+1] == 'S') || (v[i-1][j-1] == 'S' && v[i+1][j+1] == 'M'))
                    if ((v[i-1][j+1] == 'M' && v[i+1][j-1] == 'S') || (v[i-1][j+1] == 'S' && v[i+1][j-1] == 'M'))
                        ret++;

            }
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    vector<string> v;
    while (getline(cin, str))
        v.push_back(str);
    cout << x_sam(v) << endl;
    return 0;
}