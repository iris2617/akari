#include<iostream>
#define iris 70000
using namespace std;

long long square[iris+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
	long long n,i,p,q,m;
	
	for(i=1;i<=iris;i++)
	{
		square[i]=i*i;
	}
	
	while(cin>>n && n)
	{
		p=1,q=iris;
		while(p<q)
		{
			m=(p+q)/2;
			if(square[m]<n)
				p=m+1;
			else
				q=m;
		}
		if(square[p]==n)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	
	return 0;
}
