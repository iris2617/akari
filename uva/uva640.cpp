#include<iostream>
#define iris 1000000
using namespace std;

bool used[iris+10];

inline int sana(int a)
{
	int res=a;
	while(a)
	{
		res+=a%10;
		a/=10;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i,a;
	
	for(i=1;i<=iris;i++)
	{
		a=sana(i);
		if(a<=iris)
		{
			used[a]=1;
		}
		if(!used[i])
		{
			cout<<i<<'\n';
		}
	}
	
	return 0;
}
