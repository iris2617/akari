#include<iostream>
#include<memory.h>
#define loli long long
#define qwq 1000000007
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	char c[33333];
	int i,a,ans,b,p,l;
	
	cin>>s;
	for(b=s.size(),i=0,p=0,a=0;i<b;i++)
	{
		if(s[i]>'9')
		{
			if(a>0)
				while(--a)
				{
					c[p]=s[l];
					p++;
				}
			c[p]=s[i];
			p++;
			l=i;
		}
		else
		{
			a=a*10+s[i]-'0';
			if(a>5)
				a=5;
		}
	}
	if(a>0)
		while(--a)
		{
			c[p]=s[l];
			p++;
		}
	b=p;
	for(i=6,p=0,ans=0;i<b;i++)
	{
		if(c[i]==c[p])
		{
			if(c[i+1]==c[p+1]&&c[i+2]==c[p+2])
			{
				i+=2;
				p=(p+3)%6;
				if(p==0)
					ans++;
			}
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}
