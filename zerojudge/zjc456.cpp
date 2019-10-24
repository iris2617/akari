#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;

vector<int> edge[5010];
int degree[5010],order[5010];
bool used[5010];
int ds[5010];

int find(int a)
{
	return ds[a]=((a==ds[a])?a:find(ds[a]));
}

inline void uni(int a,int b)
{
	ds[find(a)]=ds[find(b)];
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	degree[5005]=9999;
	int n,m,a,b,i,j,cnt,aoi,ans;
	cin>>n>>m;
	
	while(m--)
	{
		cin>>a>>b;
		edge[a].emplace_back(b);
		edge[b].emplace_back(a);
		degree[a]++;
		degree[b]++;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=1,a=5005;j<=n;j++)
		{
			if(degree[j]<degree[a] && !used[j])
			{
				a=j;
			}
		}
		
		used[a]=1;
		order[n-i-1]=a;
		
		for(int v:edge[a])
		{
			b=v;
			if(!used[b])
			{
				degree[a]--;
				degree[b]--;
			}
		}
	}
	
	memset(used,0,sizeof(used));
	for(i=1;i<=n;i++)
	{
		ds[i]=i;
	}
	
	for(i=0,ans=0;i<n;i++)
	{
		a=order[i];
		used[a]=1;
		
		for(int v:edge[a])
		{
			b=v;
			if(used[b])
			{
				uni(a,b);
				degree[a]++;
				degree[b]++;
			}
		}
		
		for(j=1,cnt=0,aoi=9999;j<=n;j++)
		{
			if(find(j)==find(a))
			{
				cnt++;
				aoi=min(aoi,degree[j]);
			}
		}
		
		ans=max(ans,cnt*aoi);
	}
	cout<<ans<<'\n';
	
	return 0;
}
