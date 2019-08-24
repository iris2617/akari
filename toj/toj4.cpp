#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool orz;
	int T,n,l,i,j,k,b[60],c[60],a,d[60],ii,h;
	string s[1000],u[1000],qwq[1000];
	pair<int,string> t[1000];
	cin>>T;
	for(ii=1;ii<=T;ii++)
	{
		a=0;
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		cin>>n>>l;
		for(i=0;i<n;i++)
		{
			cin>>s[i];
			for(j=0;j<l;j++)
				if(s[i][j]=='1')
					b[j]++;
		}
		for(i=0;i<n;i++)
		{
			cin>>t[i].second;
			qwq[i]=t[i].second;
			for(j=0;j<l;j++)
			{
				if(t[i].second[j]=='1')
				{
					c[j]++;
				}
			}
		}
		for(i=0;i<l;i++)
		{
			if(b[i]+c[i]==n)
			{
				if(b[i]!=c[i])
				{
					a++;
					for(k=0;k<n;k++)
					{
						if(s[k][i]=='1')
							s[k][i]='0';
						else
							s[k][i]='1';
					}
				}
			}
			else if(b[i]!=c[i])
			{
				cout<<"Case #"<<ii<<": IMPOSSIBLE\n";
				goto www;
			}
		}
		sort(s,s+n);
		sort(qwq,qwq+n);
		
		for(i=0;i<n;i++)
		{
			t[i].first=0;
			for(j=0;j<l;j++)
			{
				if(s[0][j]!=t[i].second[j])
					t[i].first++;
			}
		}
		
		sort(t,t+n);
		for(k=0;k<n;k++)u[k]=s[k];
		sort(u,u+n);
		for(j=0;j<n;j++)
		{
			if(u[j]!=qwq[j])
				goto hi;
		}
		cout<<"Case #"<<ii<<": "<<a<<"\n";
		goto www;
		hi:;
		
		for(i=0;i<n;i++)
		{
			for(k=0;k<n;k++)u[k]=s[k];
			h=0,orz=0;
			for(j=0;j<l;j++)
			{
				
				if(s[0][j]!=t[i].second[j])
				{
					h++;
					for(k=0;k<n;k++)
					{
						if(s[k][j]=='1')
							u[k][j]='0';
						else
							u[k][j]='1';
					}
				}
			}
			sort(u,u+n);
			for(j=0;j<n;j++)
			{
				if(u[j]!=qwq[j])
					goto qq;
			}
			orz=1;
			cout<<"Case #"<<ii<<": "<<a+h<<"\n";
			break;
			qq:;
		}
		if(orz==0)
			cout<<"Case #"<<ii<<": IMPOSSIBLE\n";
		www:;
	}
}
