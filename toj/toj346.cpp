#include<iostream>
using namespace std;
typedef long long loli;

loli a[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	loli n,i;
	a[0]=0;
	a[1]=1;
	for(i=2;i<=90;i++)
		a[i]=a[i-2]-a[i-1];
	cin>>n;
	while(n--)
	{
		cin>>i;
		cout<<"G("<<i<<") = "<<a[i]<<'\n';
	}
	
	return 0;
}

