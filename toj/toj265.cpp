#include<iostream>
#include<algorithm>
using namespace std;
typedef long long loli;

pair<int,pair<int,int> > akari[100010];
int aoi[45010],sana[45010];
int sagiri[1000010];

inline int fhana(int a)
{
	while(aoi[a]!=a)
		a=aoi[a];
	return a;
}

inline void ub33(int a,int b)
{
	if(a!=b)
	{
		aoi[a]=b;
		sana[b]+=sana[a];
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,q,a,b,c,i;
	cin>>n>>m>>q;
	for(i=1;i<=n;i++)
	{
		aoi[i]=i;
		sana[i]=1;
	}
	for(i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		akari[i]=make_pair(c,make_pair(a,b));
	}
	sort(akari,akari+m);
	for(i=0;i<m;i++)
	{
		a=akari[i].second.first;
		b=akari[i].second.second;
		c=akari[i].first;
		a=fhana(a);
		b=fhana(b);
		if(c>1000000)
			break;
		if(i>0)
		{
			sagiri[c]=sagiri[akari[i-1].first];
			sagiri[c]-=sana[a]*(sana[a]-1);
			if(a!=b)
				sagiri[c]-=sana[b]*(sana[b]-1);
		}
		ub33(a,b);
		sagiri[c]+=sana[b]*(sana[b]-1);
	}
	for(i=1;i<=1000000;i++)
	{
		if(sagiri[i]==0)
			sagiri[i]=sagiri[i-1];
	}
	while(q--)
	{
		cin>>a;
		cout<<sagiri[a]<<'\n';
	}
	
	return 0;
}
