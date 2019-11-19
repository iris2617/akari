#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int ouo[256][256];
int cnt;

void Report(int a,int b,int c,int d,int e,int f)
{
	cnt++;
	ouo[a][b]=cnt;
	ouo[c][d]=cnt;
	ouo[e][f]=cnt;
}

void msol (int n, int bx, int by, int fx, int fy)
{
	if (n==1) return;
	// middle x, middle y
	int mx = bx+(n>>1), my = by+(n>>1);
	if (fx>=mx && fy>=my) // 4
	{
		Report(mx-1,my,mx-1,my-1,mx,my-1);
		msol(n>>1,bx,my,mx-1,my);
		msol(n>>1,bx,by,mx-1,my-1);
		msol(n>>1,mx,by,mx,my-1);
		msol(n>>1,mx,my,fx,fy);
	}
	else if (fx>=mx && fy<my) //3
	{
		Report(mx-1,my,mx-1,my-1,mx,my);
		msol(n>>1,bx,my,mx-1,my);
		msol(n>>1,bx,by,mx-1,my-1);
		msol(n>>1,mx,my,mx,my);
		msol(n>>1,mx,by,fx,fy);
	}
	else if (fx<mx && fy>=my) // 1
	{
		Report(mx-1,my-1,mx,my-1,mx,my);
		msol(n>>1,bx,by,mx-1,my-1);
		msol(n>>1,mx,by,mx,my-1);
		msol(n>>1,mx,my,mx,my);
		msol(n>>1,bx,my,fx,fy);
	}
	else if (fx<mx && fy<my) // 2
	{
		Report(mx-1,my,mx,my-1,mx,my);
		msol(n>>1,bx,my,mx-1,my);
		msol(n>>1,mx,by,mx,my-1);
		msol(n>>1,mx,my,mx,my);
		msol(n>>1,bx,by,mx-1,my-1);
	}
}

void solve (int n, int x, int y)
{
	msol(n,1,1,x,y);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,a,b,i,j;
	cin>>n;
	cin>>a>>b;
	solve(n,a,b);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<setw(3)<<(ouo[i][j]);
		}
		cout<<'\n';
	}
	cout<<cnt<<'\n';

	return 0;
}
