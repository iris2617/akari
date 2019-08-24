#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define loli long long
using namespace std;

int akari[1010];
bool sana[1005000];
int sagiri[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	
	int n,aoi=0,a,shigure,nozomi=0,x=0,i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>akari[i];
		aoi+=akari[i];
	}
	sagiri[nozomi]=0;
	nozomi++;
	sana[0]=1;
	for(i=0;i<n;i++)
	{
		shigure=nozomi;
		for(j=0;j<shigure;j++)
		{
			a=sagiri[j]+akari[i];
			if(!sana[a]&&a<=aoi/2)
			{
				sana[a]=1;
				sagiri[nozomi]=a;
				nozomi++;
				x=max(x,a);
			}
		}
	}
	cout<<x<<' '<<aoi-x<<'\n';
	
	return 0;
}

