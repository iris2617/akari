#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
#include<memory.h>
#include<vector>
#include<bitset>
using namespace std;

int st[8000000],a,b,x=1;

int query(int l,int r,int i)
{
	if(a<=l&&b>=r)
		return st[i];
	else if(a<=r&&b>=l)
		return max(query(l,(l+r)/2,i*2),query((l+r+1)/2,r,i*2+1));
	else
		return -2147483648;
}

void update(int i)
{
	int u;
	u=max(st[i*2],st[i*2+1]);
	if(u!=st[i]&&i>1)
	{
		st[i]=u;
		update(i/2);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,t,i;
	char c;
	
	cin>>n;
	while(x<n)x*=2;
	for(i=x;i<x+n;i++)
		cin>>st[i];
	
	for(i=x-1;i>0;i--)
	{
		st[i]=max(st[i*2],st[i*2+1]);
	}
	
	cin>>t;
	
	while(t--)
	{
		cin>>c>>a>>b;
		if(c=='Q')
		{
			cout<<query(1,x,1)/2<<"\n";
		}
		else
		{
			st[x+a-1]=b;
			update((x+a-1)/2);
		}
	}
}
