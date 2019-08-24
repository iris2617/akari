#include<iostream>
#include<vector>
using namespace std;

vector<int> akari[200010];
int aoi[2000010],k;

int sana(int a,int w)
{
	int i,b,f=0,iris=0;
	aoi[a]=0;
	for(i=0;i<akari[a].size();i++)
	{
		b=akari[a][i];
		iris+=sana(b,w);
		aoi[a]=max(aoi[a],aoi[b]);
	}
	aoi[a]=(aoi[a]+1)%w;
	if(aoi[a]==0||a==1)
		return iris+1;
	return iris;
}

int search(int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		if(sana(1,m)<=k)
			return search(l,m);
		return search(m+1,r);
	}
	else
		return l;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,i,a;
	cin>>n>>k;
	for(i=2;i<=n;i++)
	{
		cin>>a;
		akari[a].emplace_back(i);
	}
	cout<<search(1,200010)<<'\n';
	
	return 0;
}
