#include<iostream>
#define loli long long
#define qwq 2147483647
using namespace std;

int a[100010],b[100010],c[100010],lis[100010],s,l,r;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,i,j;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
			cin>>b[i];
		for(i=0;i<n;i++)
			c[a[i]]=i;
		for(i=0;i<n;i++) 
			b[i]=c[b[i]];
		s=0;
		lis[0]=-1;
		for(i=0;i<n;i++)
		{
			for(l=0,r=s+1;l<r;)
			{
				if(lis[(l+r)/2]<b[i])
					l=(l+r)/2+1;
				else
					r=(l+r)/2;
			}
			if(l>s)
				s++;
			lis[l]=b[i];
		}
		cout<<s<<'\n';
	}
	
    return 0;
}
