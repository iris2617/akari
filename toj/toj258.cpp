#include<iostream>
#include<queue>
#include<vector>
#include<memory.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define ll long long
using namespace std;

pair <ll,ll> dot[1000010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n,i,j,x,y,a,b,ans=9999999999999999;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
		dot[i]=make_pair(x,y);
	}
	
	sort(dot,dot+n);
	
	for(i=0;i<n-1;i++)
	{
		x=dot[i].first;
		y=dot[i].second;
		for(j=i+1;j<n;j++)
		{
			a=dot[j].first;
			b=dot[j].second;
			if((a-x)*(a-x)>=ans)
				break;
			
			ans=min(ans,(x-a)*(x-a)+(y-b)*(y-b));
		}
	}
	
	cout<<fixed<<setprecision(6)<<sqrt(ans)<<'\n';
}
