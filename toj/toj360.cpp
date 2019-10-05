#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

bool used[10];
bool akari[10][10];
bool sana[10][10];
int ouo[10];

bool check(int n)
{
	int a,b,i,j;
	memset(used,0,sizeof(used));
	memset(sana,0,sizeof(sana));
	
	used[ouo[0]]=1;
	for(i=1;i<n;i++)
	{
		a=ouo[i-1];
		b=ouo[i];
		if( (a+b)==10 || ( (a&1) && (b&1) && a!=5 && b!=5) )
		{
			if(!used[(a+b)>>1])
				return 0;
			else
			{
				sana[a][(a+b)>>1]=1;
				sana[(a+b)>>1][a]=1;
				sana[(a+b)>>1][b]=1;
				sana[b][(a+b)>>1]=1;
			}
		}
		else
		{
			sana[a][b]=1;
			sana[b][a]=1;
		}
		used[b]=1;
	}
	
	for(i=1;i<10;i++)
		for(j=1;j<10;j++)
			if(sana[i][j]!=akari[i][j])
				return 0;
	
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int m,n,p=0,a,b,i;
	
	cin>>m;
	while(m--)
	{
		cin>>a>>b;
		akari[a][b]=1;
		akari[b][a]=1;
		if(!used[a])
			used[a]=1;
		if(!used[b])
			used[b]=1;
	}
	
	for(i=1,n=0;i<=9;i++)
		if(used[i])
			ouo[n++]=i;
	
	do{
		if(check(n))
		{
			for(int i=0;i<n;i++)
				cout<<ouo[i];
			cout<<'\n';
		}
	}
	while(next_permutation(ouo,ouo+n));
	
	return 0;
}
