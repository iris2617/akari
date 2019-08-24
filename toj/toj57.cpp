#include<iostream>
#include<memory.h>
#include<iomanip>
#define loli long long
#define qwq 433494437
using namespace std;

int state[111][7];
loli p;

struct aa{
	loli a[111][111];
};

aa mul(aa a,aa b)
{
	aa c;
	memset(&c,0,sizeof(c));
	int i,j,k;
	for(i=0;i<p;i++)
	{
		for(j=0;j<p;j++)
		{
			for(k=0;k<p;k++)
			{
				c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%qwq;
			}
		}
	}
	return c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	aa a,b;
	memset(&a,0,sizeof(a));
	memset(&b,0,sizeof(b));
	loli n,m,c,i,j,k,l,ans;
	bool flag;
	
	cin>>n>>m>>c;
	if(n>m)
		swap(n,m);
	m--;
	
	if(c<=1)
	{
		if(n*m>1)
			cout<<"0\n";
		else
			cout<<"1\n";
	}
	else if(c==2)
		cout<<"2\n";
	else if(n==1)
	{
		ans=c;
		c--;
		while(m>0)
		{
			if(m&1)
			{
				ans=(ans*c)%qwq;
			}
			c=(c*c)%qwq;
			m>>=1;
		}
		cout<<ans<<'\n';
	}
	else
	{
		p=0;
		for(i=1;i<=c;i++)
		{
			for(j=1;j<=c;j++)
			{
				if(i!=j)
				{
					if(n>=3)
					for(k=1;k<=c;k++)
					{
						if(j!=k)
						{
							if(n>=4)
							for(l=1;l<=c;l++)
							{
								if(k!=l)
								{
									state[p][0]=i,state[p][1]=j;
									state[p][2]=k,state[p][3]=l;
									p++;
								}
							}
							else
							{
								state[p][0]=i,state[p][1]=j,state[p][2]=k;
								p++;
							}
						}
					}
					else
					{
						state[p][0]=i,state[p][1]=j;
						p++;
					}
				}
			}
		}
		//
		for(i=0;i<p;i++)
		{
			for(j=0;j<p;j++)
			{
				for(k=0,flag=1;k<n;k++)
				{
					if(state[i][k]==state[j][k])
						flag=0;
				}
				b.a[i][j]=flag;
			}
			a.a[0][i]=1;
		}
		//
		while(m>0)
		{
			if(m&1)
			{
				a=mul(a,b);
			}
			b=mul(b,b);
			m>>=1;
		}
		for(i=0,ans=0;i<p;i++)
			ans=(ans+a.a[0][i])%qwq;
		
		cout<<ans<<'\n';
	}
	
    return 0;
}
