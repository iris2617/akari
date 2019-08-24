#include<iostream>
#include<cmath>
#include<algorithm>
#define loli long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,a,i;
	string s;
	char c;
	getline(cin,s);
	for(i=0,n=0;s[i]!=' ';i++)
	{
		n=n*10+s[i]-'0';
	}
	c=s[s.size()-1];
	for(i=0;i<n;i++)
	{
		cin>>a;
		if(i>0)
			cout<<c;
		cout<<a;
	}
	cout<<'\n';
	
	return 0;
}

