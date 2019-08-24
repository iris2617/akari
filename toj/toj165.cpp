#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
#include<memory.h>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t,a,b,i,n,m,leader[100005];
	
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=1;i<=n;i++)
		{
			leader[i]=i;
		}
		while(m--)
		{
			cin>>a>>b;
			while(b!=leader[b])
			{
				b=leader[b];
			}
			leader[b]=a;
		}
		for(i=1;i<=n;i++)
		{
			a=i;
			while(a!=leader[a])a=leader[a];
			cout<<a<<'\n';
		}
	}
	
}
