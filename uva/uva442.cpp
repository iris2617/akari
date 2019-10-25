#include<iostream>
#define iris 70000
using namespace std;

int x[256],y[256];
int xs[256],ys[256],p,ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    int n,a,b,ans,i;
    string s;
    char c;
    bool f;
    
    cin>>n;
    while(n--)
    {
    	cin>>c;
		cin>>x[c]>>y[c];
	}
	
	while(cin>>s)
	{
		n=s.size();
		f=p=ans=0;
		
		for(i=0;i<n;i++)
		{
			c=s[i];
			
			if(c==')')
			{
				a=p-2,b=p-1;
				if(ys[a]==xs[b])
				{
					ans+=xs[a]*ys[a]*ys[b];
					p--;
					ys[a]=ys[b];
				}
				else
				{
					f=1;
					break;
				}
			}
			else if(c!='(')
			{
				xs[p]=x[c];
				ys[p++]=y[c];
			}
		}
		
		if(f)
			cout<<"error\n";
		else
			cout<<ans<<'\n';
	}
	
	return 0;
}
