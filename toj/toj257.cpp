#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int dp[4010][4010];
char o[256];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	o['A']='T';
	o['T']='A';
	o['G']='C';
	o['C']='G';
	
	string a,b;
	int i,j,c,d,e;
	cin>>a>>b;
	c=a.size();
	d=b.size();
	for(i=1;i<=c;i++)
		for(j=1;j<=d;j++)
			dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]+(a[i-1]==b[j-1]));
	e=dp[c][d]*2;
	memset(dp,0,sizeof(dp));
	for(i=0;i<c;i++)
		a[i]=o[a[i]];
	for(i=1;i<=c;i++)
		for(j=1;j<=d;j++)
			dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]+(a[i-1]==b[j-1]));
	e=max(e,dp[c][d]*2);
	c=c+d;
	if(e)
	{
		d=__gcd(c,e);
		c/=d;
		e/=d;
	}
	cout<<e<<'/'<<c<<'\n';
	
	return 0;
}
