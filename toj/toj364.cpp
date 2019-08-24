#include<iostream>
#include<algorithm>
using namespace std;
typedef long long loli;

int akari[10010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,aoi,i,sana,a,b,sagiri=2147483647;
	cin>>n>>a>>b;
	
	if(a==b)
	{
		cout<<0<<'\n';
		return 0;
	}
	
	for(i=0;i<n;i++)
	{
		cin>>aoi>>sana;
		if(akari[aoi]>0)
			akari[aoi]=min(akari[aoi],sana);
		else
			akari[aoi]=sana;
	}
	aoi=__gcd(a,b);
	a/=aoi;
	b/=aoi;
	for(i=1;a*i<=10000&&b*i<=10000;i++)
	{
		if(akari[a*i]>0&&akari[b*i]>0)
		{
			sagiri=min(sagiri,akari[a*i]+akari[b*i]);
		}
	}
	if(sagiri>30071883)
		cout<<-1<<'\n';
	else
		cout<<sagiri<<'\n';
	
	return 0;
}
