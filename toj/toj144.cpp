#include<iostream>
#include<vector>
using namespace std;

vector<int> akari[100010];
int aoi,sana;

void dfs(int a,int f,int d)
{
	int i,b;
	for(i=0;i<akari[a].size();i++)
	{
		b=akari[a][i];
		if(b!=f)
		{
			dfs(b,a,d+1);
		}
	}
	if(d>aoi)
	{
		aoi=d;
		sana=a;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,a,b,i;
	cin>>n>>m;
	while(m--)
	{
		cin>>a>>b;
		akari[a].emplace_back(b);
		akari[b].emplace_back(a);
	}
	aoi=0;
	sana=0;
	dfs(0,-1,0);
	dfs(sana,-1,0);
	cout<<aoi<<'\n';
	return 0;
}
