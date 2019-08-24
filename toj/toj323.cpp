#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
typedef long long loli;

int akari[10010],lys0829[10010];
int aoi,sana;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,k,a,i;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>a;
		akari[a]=i;
	}
	while(k--)
	{
		aoi=0;
		memset(lys0829,0x3f,sizeof(lys0829));
		
		for(i=0;i<n;i++)
		{
			cin>>a;
			a=akari[a];
			sana=upper_bound(lys0829,lys0829+aoi+1,a)-lys0829;
			lys0829[sana]=a;
			aoi=max(aoi,sana);
		}
		cout<<aoi+1<<'\n';
	}
	
	return 0;
}
