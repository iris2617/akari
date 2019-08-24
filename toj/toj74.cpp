#include<iostream>
#include<algorithm>
typedef int loli;
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	
	int i,p,n;
	bool lys0829,ouo;
	string s;
	while(cin>>s)
	{
		n=s.size();
		for(p=1,lys0829=0;p<n&&!lys0829;p++)
		{
			if(n%p==0)
			{
				for(i=p,ouo=0;i<n;i++)
				{
					if(s[i]!=s[i%p])
					{
						ouo=1;
						break;
					}
				}
				if(ouo==1)
				{
					p=i;
				}
				else
				{
					lys0829=1;
					p--;
				}
			}
		}
		s.erase(p);
		cout<<s<<'\n';
	}
	
	return 0;
}

