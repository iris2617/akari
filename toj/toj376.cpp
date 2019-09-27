#include<iostream>
#include<memory.h>
#define iris 1000000009
#define int long long
using namespace std;

int aaa[3][3]={
	{1,0,0},
	{0,1,0},
	{0,0,1}
};
int bbb[3][3]={
	{1,1,1},
	{1,0,0},
	{0,0,1}
};
int ouo[3][3],akari[3][3],sagiri[3][3],nanami[3][3];

void mul(int (*&a)[3],int (*&b)[3],int (*&c)[3])
{
	int i,j,k;
	memset(*c,0,sizeof(*c)*3);
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			for(k=0;k<3;k++)
				c[i][j]=(c[i][j]+a[i][k]*b[k][j])%iris;
	swap(a,c);
	return;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,(*a)[3]=ouo,(*b)[3]=akari,(*c)[3]=sagiri,(*d)[3]=nanami;
	while(cin>>n)
	{
		memcpy(*a,aaa,sizeof(aaa));
		memcpy(*b,bbb,sizeof(bbb));
		memcpy(*d,aaa,sizeof(aaa));
		while(n)
		{
			if(n&1)
			{
				mul(a,b,c);
			}
			mul(b,b,c);
			n>>=1;
		}
		mul(d,a,c);
		cout<<d[0][2]<<'\n';
	}
	
	return 0;
}

