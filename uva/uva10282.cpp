#include<iostream>
#include<sstream> 
#include<unordered_map>
using namespace std;

unordered_map<string,string> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stringstream ss;
	string a,b;
	
	while(getline(cin,a) && !a.empty())
	{
		ss.clear();
		ss<<a;
		ss>>a;
		ss>>b;
		m[b]=a;
	}
	
	while(cin>>a)
	{
		cout<<(m[a].empty()?"eh":m[a])<<'\n';
	}
	
	return 0;
}
