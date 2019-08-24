#include<iostream>
#include<algorithm>
using namespace std;
long long a[3][8],w[3][8];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i,j,n,b,c,d,e;
	cin>>n;
	while(n--)
	{
		cin>>b>>c>>d>>e;
		a[b-1][c*4+d*2+e]++;
	}
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			w[1][i|j]+=a[0][i]*a[1][j];
		}
	}
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			w[2][i|j]+=w[1][i]*a[2][j];
		}
	}
	cout<<w[2][7]<<'\n';
	
	return 0;
}
