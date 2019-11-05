#include<iostream>
#include<algorithm>
using namespace std;

int tag[200010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,i,ans;
	cin>>n>>m;
	for(i=0;i<m*2;i++)
	{
		cin>>tag[i];
		if(i&1)
			tag[i]++;
	}
	sort(tag,tag+m*2);
	for(i=ans=0;i<m*2;i+=2)
	{
		ans+=tag[i+1]-tag[i];
	}
	cout<<n-ans<<'\n';
	
	return 0;
}zj
