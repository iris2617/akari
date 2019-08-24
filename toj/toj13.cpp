#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int v,n,c[100001],w[100],b[100],i,j;
	while(cin>>v>>n)
	{
		memset(c,0,sizeof(c));
		for(i=0;i<n;i++)cin>>w[i]>>b[i];
		for(i=0;i<n;i++)
		{
			for(j=w[i];j<=v;j++)
			{
				c[j]=max(c[j],c[j-w[i]]+b[i]);
			}
		}
		cout<<c[v]<<'\n';
	}
}
