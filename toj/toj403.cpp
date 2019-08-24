#include<iostream>
#include<memory.h>
#define loli long long
#define qwq 1000000007
using namespace std;

int g[22][22],x,y,H,W,owo,qq,ans=2147483647;
int dp[22][22][22][22][4];
int ouo[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool visited[22][22];

void gogogo(int a,int b,int d,int w,int up,int lt,int dn,int rt)
{
	w+=g[a][b];
	qq++;
	if(visited[a][b]==1)
		return;
	else if(a==x&&b==y)
	{
		owo++;
		ans=min(ans,w);
		return;
	}
	else if(a<up||a>dn||b<lt||b>rt)
		return;
	else if(d==0&&b>y)
		return;
	else if(d==1&&a<x)
		return;
	else if(d==2&&b<y)
		return;
	else if(d==3&&a>x)
		return;
	visited[a][b]=1;
	
	gogogo(a+ouo[d][0],b+ouo[d][1],d,w,up,lt,dn,rt);
	d=(d+1)%4;
	if(d==0)
	{
		up--;
		lt=b;
		if(w<dp[up][lt][dn][rt][d])
		{
			dp[up][lt][dn][rt][d]=w;
			gogogo(a+ouo[d][0],b+ouo[d][1],d,w,up,lt,dn,rt);
		}
	}
	else if(d==1)
	{
		lt++;
		dn=a;
		if(w<dp[up][lt][dn][rt][d])
		{
			dp[up][lt][dn][rt][d]=w;
			gogogo(a+ouo[d][0],b+ouo[d][1],d,w,up,lt,dn,rt);
		}
	}
	else if(d==2)
	{
		dn++;
		rt=b;
		if(w<dp[up][lt][dn][rt][d])
		{
			dp[up][lt][dn][rt][d]=w;
			gogogo(a+ouo[d][0],b+ouo[d][1],d,w,up,lt,dn,rt);
		}
	}
	else if(d==3)
	{
		rt--;
		up=a;
		if(w<dp[up][lt][dn][rt][d])
		{
			dp[up][lt][dn][rt][d]=w;
			gogogo(a+ouo[d][0],b+ouo[d][1],d,w,up,lt,dn,rt);
		}
	}
	visited[a][b]=0;
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i,j;
	
	memset(dp,1,sizeof(dp));
	
	cin>>H>>W>>x>>y;
	for(i=1;i<=H;i++)
		for(j=1;j<=W;j++)
			cin>>g[i][j];
	
	gogogo(1,1,0,0,1,1,H,W);
	
	cout<<ans<<'\n';
	
	return 0;
}
