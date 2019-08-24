#include<iostream>
#include<algorithm>
using namespace std;

pair<int,pair<int,int> > edge[500005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i,k,r,a,b,c,d,n[1005],ans=0;
	
	cin>>k>>r;
	for(i=0;i<k;i++)n[i]=i;
	for(i=0;i<r;i++)
	{
		cin>>a>>b>>c;
		edge[i]=make_pair(c,make_pair(a,b));
	}
	sort(edge,edge+r);
	for(i=0;i<r;i++)
	{
		a=edge[i].second.first;
		b=edge[i].second.second;
		while(a!=n[a])a=n[a];
		while(b!=n[b])b=n[b];
		if(a!=b)
		{
			n[a]=b;
			k--;
			ans+=edge[i].first;
		}
	}
	if(k==1)
		cout<<ans<<'\n';
	else
		cout<<"-1\n";
	return 0;
}

