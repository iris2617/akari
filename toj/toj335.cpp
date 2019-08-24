#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

pair<int,pair<int,int> > p[1000010];
int akari[100010],d[100010];
vector<pair<int,int> > sagiri[100010];
bool v[100010];
int aoi[100010][25],qwq[100010][20];

int sana(int a)
{
	while(akari[a]!=a)
		a=akari[a];
	return a;
}

void utaha(int a,int b)
{
	akari[sana(a)]=sana(b);
	return;
}

void sora(int a)
{
	int nanahira=sagiri[a].size();
	v[a]=1;
	int i,b;
	for(i=1;(1<<i)<=d[a];i++)
	{
		aoi[a][i]=aoi[aoi[a][i-1]][i-1];
		qwq[a][i]=min(qwq[a][i-1],qwq[aoi[a][i-1]][i-1]);
	}
	for(i=0;i<nanahira;i++)
	{
		b=sagiri[a][i].first;
		if(!v[b])
		{
			aoi[b][0]=a;
			d[b]=d[a]+1;
			qwq[b][0]=sagiri[a][i].second;
			sora(b);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,i,j,a,b,c,q,ans;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		akari[i]=i;
	}
	for(i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		p[i]=make_pair(c,make_pair(a,b));
	}
	sort(p,p+m);
	for(i=m-1,j=0;j<n-1;i--)
	{
		a=p[i].second.first;
		b=p[i].second.second;
		c=p[i].first;
		if(sana(a)!=sana(b))
		{
			j++;
			utaha(a,b);
			sagiri[a].emplace_back(make_pair(b,c));
			sagiri[b].emplace_back(make_pair(a,c));
		}
	}
	d[0]=0;
	sora(0);
	
	cin>>q;
	while(q--)
	{
		ans=2147483647;
		cin>>a>>b;
		if(d[a]<d[b])
			swap(a,b);
		for(i=20;i>=0;i--)
		{
			if(d[a]-(1<<i)>=d[b])
			{
				ans=min(ans,qwq[a][i]);
				a=aoi[a][i];
			}
		}
		for(i=20;i>=0;i--)
		{
			if(aoi[a][i]!=aoi[b][i])
			{
				ans=min(ans,qwq[a][i]);
				ans=min(ans,qwq[b][i]);
				a=aoi[a][i];
				b=aoi[b][i];
			}
		}
		if(a!=b)
			ans=min(ans,min(qwq[a][0],qwq[b][0]));
		cout<<ans<<'\n';
	}
	
	return 0;
}

