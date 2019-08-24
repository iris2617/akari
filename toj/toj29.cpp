#include<iostream>
#include<memory.h>
#include<vector>
#include<queue>
using namespace std;
typedef long long loli;

vector<int> key[50010];
int gogo[50010][28],p;
queue<int> q;
bool ans[50010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t,n,i,j,a,b,ouo;
	string s,k;
	cin>>t;
	while(t--)
	{
		memset(gogo,0,sizeof(gogo));
		memset(ans,0,sizeof(ans));
		while(!q.empty())
			q.pop();
		for(i=0;i<50010;i++)
			key[i].clear();
		
		cin>>s;
		cin>>n;
		for(ouo=0;ouo<n;ouo++)
		{
			cin>>k;
			a=0;
			b=k.size();
			for(i=0;i<b;i++)
			{
				if(gogo[a][k[i]-'a']==0)
				{
					gogo[a][k[i]-'a']=++p;
				}
				a=gogo[a][k[i]-'a'];
				if(i==b-1)
				{
					key[p].emplace_back(ouo);
				}
			}
		}
		//
		b=s.size();
		for(i=-1;i<b;i++)
		{
			q.push(0);
			p=q.size()-1;
			while(p--)
			{
				a=q.front();
				if(key[a].size()>0)
				{
					for(j=0;j<key[a].size();j++)
					{
						ans[key[a][j]]=1;
					}
				}
				
				if(gogo[a][s[i]-'a']>0)
				{
					q.push(gogo[a][s[i]-'a']);
				}
				
				q.pop();
			}
		}
		for(i=0;i<n;i++)
		{
			if(ans[i])
				cout<<"y\n";
			else
				cout<<"n\n";
		}
	}
	
	return 0;
}


