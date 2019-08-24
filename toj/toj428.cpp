#include<iostream>
using namespace std;
typedef long long loli;

int node[6600000][2],p;
int flag[6600000];

void push(int b)
{
	int i,a;
	bool c;
	a=0;
	
	for(i=30;i>=0;i--)
	{
		c=b&(1<<i);
		if(node[a][c]==0)
		{
			node[a][c]=++p;
		}
		a=node[a][c];
	}
	flag[a]++;
}

void pop(int b,int a,int k)
{
	bool c;
	c=b&(1<<k);
	
	if(k>=0)
	{
		pop(b,node[a][c],k-1);
		if(k==0)
		{
			if(flag[node[a][c]]==0)
			{
				node[a][c]=0;
			}
		}
		else if(node[node[a][c]][0]==0&&node[node[a][c]][1]==0)
		{
			node[a][c]=0;
		}
	}
	else
	{
		flag[a]--;
	}
	
	return;
}

int query(int b)
{
	int i,a,ans;
	bool c;
	a=0;
	
	for(i=30,ans=0;i>=0;i--)
	{
		c=!(b&(1<<i));
		if(node[a][c]==0)
		{
			c=!c;
		}
		a=node[a][c];
		ans=ans*2+c;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t,a,b;
	cin>>t;
	
	push(0);
	while(t--)
	{
		cin>>a>>b;
		if(a==0)
		{
			push(b);
		}
		else if(a==1)
		{
			pop(b,0,30);
		}
		else
		{
			cout<<(b^query(b))<<'\n';
		}
	}
	
	return 0;
}


