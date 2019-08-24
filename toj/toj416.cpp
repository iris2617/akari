#include<iostream>
#include<queue>
#include<vector>
#include<memory.h>
#define mod 1000000007
using namespace std;

struct matrix{
	long long m[8][8];
};

matrix mul(matrix a,matrix b,bool x)
{
	matrix c;
	memset(c.m,0,sizeof(c.m));
	
	int i,j,k,n=6;
	if(x==1)
		n=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<6;j++)
		{
			for(k=0;k<6;k++)
			{
				c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
			}
		}
	}
	
	return c;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	matrix a,b;
	int i,ans,n;
	
	while(cin>>n)
	{
		memset(a.m,0,sizeof(a.m));
		memset(b.m,0,sizeof(b.m));
		a.m[0][0]=1,a.m[0][1]=1,a.m[0][3]=1;
		
		b.m[0][1]=1,b.m[0][3]=1,b.m[1][0]=1,b.m[1][2]=1;
		b.m[1][3]=1,b.m[2][0]=1,b.m[2][3]=1,b.m[3][3]=1;
		b.m[4][3]=1,b.m[4][5]=1,b.m[5][3]=1,b.m[0][0]=1;
		b.m[3][4]=1;
		
		n--;
		while(n>0)
		{
			if(n&1)
			{
				a=mul(a,b,1);
			}
			b=mul(b,b,0);
			n>>=1;
		}
		for(i=0,ans=0;i<6;i++)
		{
			ans=(ans+a.m[0][i])%mod;
		}
		
		cout<<ans<<'\n';
	}
}
