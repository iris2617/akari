#include<iostream>
#include<memory.h>
#include"Pikachu.h"
#define loli long long
using namespace std;

int a0[1050000],a1[525000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n=Init(),i,p,q,b=0,ans,*sana=a0;
	for(i=1;i<n;i++)
		a0[i]=i;
	for(int m=n;m>2;b++,m/=2);
	for(ans=0;b>=0;b--,n>>=1)
	{
		for(i=1,p=1,q=1;i<n;i++)
		{
			if(GetBit(sana[i],b))
			{
				a1[q]=sana[i];
				q++;
			}
			else
			{
				a0[p]=sana[i];
				p++;
			}
		}
		if(p<q)
		{
			sana=a0;
			ans=ans*2;
		}
		else
		{
			sana=a1;
			ans=ans*2+1;
		}
	}
	Answer(ans);
	
	return 0;
}

