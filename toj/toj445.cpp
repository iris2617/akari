#include<iostream>
#include<memory.h>
#include<bitset>
#include<queue>
using namespace std;

int aoi[16][1<<15];
queue<int> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,akari,i,k,a,b,*iris=aoi[0],*ub33=aoi[1],ouo;
	string s;
	cin>>s;
	n=s.size();
	for(i=0,akari=0;i<n;i++)
		akari=(akari<<1)|(s[i]-'0');
	q.push(akari);
	for(k=1;k<=n;k++)
	{
		swap(iris,ub33);
		memset(ub33,123,sizeof(aoi[0]));
		ouo=q.size();
		while(ouo--)
		{
			akari=q.front();
			for(i=0;i<=n-k;i++)
			{
				a=((1<<k)-1)<<i;
				b=akari^a;
				if(iris[akari]+k<ub33[b])
				{
					ub33[b]=iris[akari]+k;
					q.push(b);
				}
			}
			q.pop();
			ub33[akari]=iris[akari];
			if(k<n)
				q.push(akari);
		}
	}
	cout<<ub33[0]<<'\n';
	
	return 0;
}
