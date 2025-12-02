#include <bits/stdc++.h>

using namespace std;

int main(){
	int pos=50;
	long long count=0;
	string s;
	
	while(cin>>s)
	{
		int n=stoi(s.substr(1));
		
		pos=(s[0]=='L')?(pos-n+100)%100:(pos+n)%100;
		if(pos==0)
			count++;
	}
    cout<<count;
}
