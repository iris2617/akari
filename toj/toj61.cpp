#include<iostream>
#include<queue>
#include<vector>
#include<memory.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define ll long long
using namespace std;

struct matrix{
	int m[110][110];
};
int n;

matrix mul(matrix a,matrix b,bool c)
{
	int i,j,k,x=1;
	if(c)
		x=n;
	matrix d;
	memset(d.m,0,sizeof(d.m));
	
	for(i=0;i<x;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				d.m[i][j]=(d.m[i][j]+(a.m[i][k]*b.m[k][j])%10009)%10009;
			}
		}
	}
	return d;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i,j,s,e,k;
	matrix a,b;
	
	while(cin>>n>>s>>e>>k)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cin>>b.m[i][j];
		memset(a.m,0,sizeof(a.m));
		a.m[0][s]=1;
		
		while(k>0)
		{
			if(k&1)
			{
				a=mul(a,b,0);
			}
			b=mul(b,b,1);
			k>>=1;
		}
		cout<<a.m[0][e]<<'\n';
	}
}
