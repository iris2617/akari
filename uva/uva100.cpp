#include<iostream>
using namespace std;

int dp[1000010];

inline int ouo(int n)
{
	int res=1;
	while(n>1)
	{
		res++;
		if(n&1)
			n=n*3+1;
		else
			n>>=1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i,j,ans;
	
	while(cin>>i>>j)
	{
		cout<<i<<' '<<j<<' ';
		if(i>j)
			swap(i,j);
		for(ans=0;i<=j;i++)
		{
			ans=max(ans,ouo(i));
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
