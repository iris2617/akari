#include<iostream>
#include<vector>
#include<algorithm>
#define iris 100010
using namespace std;

vector<pair<int,int> > akari[iris];
int ouo,ans;

void dfs(int a,int f,int d)
{
	int b,c;
	if(d>ans)
	{
		ouo=a;
		ans=d;
	}
	for(pair<int,int> i:akari[a])
	{
		b=i.first;
		c=i.second;
		if(b!=f)
			dfs(b,a,d+c);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,a,b,c;
	cin>>n>>m;
	while(m--)
	{
		cin>>a>>b>>c;
		akari[a].emplace_back(make_pair(b,c));
		akari[b].emplace_back(make_pair(a,c));
	}
	
	dfs(0,-1,0);
	dfs(ouo,-1,0);
	cout<<ans<<'\n';
	
	return 0;
}

