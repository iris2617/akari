#include<iostream>
using namespace std;

int sana[10010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,r,cnt=0,a,i;
	bool flag;
	
	while(cin>>n>>r)
	{
		cnt++;
		
		while(r--)
		{
			cin>>a;
			sana[a]=cnt;
		}
		
		for(i=1,flag=0;i<=n;i++)
		{
			if(sana[i]!=cnt)
			{
				flag=1;
				cout<<i<<" ";
			}
		}
		if(!flag)
		{
			cout<<'*';
		}
		cout<<'\n';
	}
	
	return 0;
}
