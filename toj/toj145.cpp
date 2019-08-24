#include<iostream>
#include<queue>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;

int arr[1010][1010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,k,q,a,b,c,d,i,j;
	cin>>n>>m>>k>>q;
	
	while(k--)
	{
		cin>>a>>b;
		arr[a+1][b+1]++;
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=2;j<=m;j++)
		{
			arr[i][j]+=arr[i][j-1];
		}
	}
	
	for(j=1;j<=m;j++)
	{
		for(i=2;i<=n;i++)
		{
			arr[i][j]+=arr[i-1][j];
		}
	}
	
	while(q--)
	{
		cin>>a>>b>>c>>d;
		c++,d++;
		cout<<arr[c][d]+arr[a][b]-arr[a][d]-arr[c][b]<<'\n';
	}
}
