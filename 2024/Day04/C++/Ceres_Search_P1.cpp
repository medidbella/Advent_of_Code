//MTRX

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int horizontal(vector<string> &v)
{
    int ret = 0;
    for(int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size() - 3; j++)
        {
            if (v[i][j] == 'X' && v[i][j+1] == 'M' && v[i][j+2] == 'A' && v[i][j+3] == 'S')
                ret++;
            if (v[i][j] == 'S' && v[i][j+1] == 'A' && v[i][j+2] == 'M' && v[i][j+3] == 'X')
                ret++;
        }
    }
    return ret;
}

int vertical(vector<string> &v)
{
    int ret = 0;
    for(int i = 0; i < v.size() - 3; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == 'X' && v[i+1][j] == 'M' && v[i+2][j] == 'A' && v[i+3][j] == 'S')
                ret++;
            if (v[i][j] == 'S' && v[i+1][j] == 'A' && v[i+2][j] == 'M' && v[i+3][j] == 'X')
                ret++;
        }
    }
    return ret;
}

int diagonal(vector<string> &v)
{
    int ret = 0;
    for(int i = 0; i < v.size() - 3; i++)
    {
        for (int j = 0; j < v[i].size() - 3; j++)
        {
            if (v[i][j] == 'X' && v[i+1][j+1] == 'M' && v[i+2][j+2] == 'A' && v[i+3][j+3] == 'S')
                ret++;
            if (v[i][j] == 'S' && v[i+1][j+1] == 'A' && v[i+2][j+2] == 'M' && v[i+3][j+3] == 'X')
                ret++;
        }
    }
    return ret;
}

int rdiagonal(vector<string> &v)
{
    int ret = 0;
    for(int i = 0; i < v.size() - 3; i++)
    {
        for (int j = 3; j < v[i].size(); j++)
        {
            if (v[i][j] == 'X' && v[i+1][j-1] == 'M' && v[i+2][j-2] == 'A' && v[i+3][j-3] == 'S')
                ret++;
            if (v[i][j] == 'S' && v[i+1][j-1] == 'A' && v[i+2][j-2] == 'M' && v[i+3][j-3] == 'X')
                ret++;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long ret = 0;
    string str;
    vector<string> v;
    while (getline(cin, str))
        v.push_back(str);
    ret += horizontal(v);
    ret += vertical(v);
    ret += diagonal(v);
    ret += rdiagonal(v);
    cout << ret << endl;
    return 0;
}