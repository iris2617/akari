#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define akari 24851
typedef int loli;
using namespace std;

int koios1143 (int n,int m)
{
	if(n<m)
		return 0;
	int ouo,ovo,i;
	m=min(m,n-m);
	for(i=n-m+1,ouo=1;i<=n;i++)
		ouo=(ouo*i)%akari;
	for(i=1,ovo=1;i<=m;i++)
		ovo=(ovo*i)%akari;
	
	int iris=akari-2,a=1;
	while(iris>0)
	{
		if(iris&1)
			a=(a*ovo)%akari;
		ovo=(ovo*ovo)%akari;
		iris>>=1;
	}
	return (ouo*a)%akari;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	
	int n,m;
	cin>>n>>m;
	n--;
	m--;
	cout<<(koios1143(n%akari,m%akari)*koios1143(n/akari,m/akari))%akari<<'\n';
	
	return 0;
}

