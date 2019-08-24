#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
#include<memory.h>
#include<vector>
#include<bitset>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,x,a,b;
	cin>>n>>x>>a>>b;
	if((x*a)%b==0)
	{
		b=(x*a)/b;
		while(n--)
		{
			cin>>a;
			if(a==b)
			{
				cout<<"Yes\n";
				goto qwq;
			}
		}
		cout<<"No\n";
	}
	else
		cout<<"No\n";
	qwq:
	return 0;
}
