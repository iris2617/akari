#include<iostream>
using namespace std;

double a[16],b[16],c[16],d[16];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	char ch;
	int n=0,cnt=0,i;
	double x,y;
	
	while(cin>>ch && ch!='*')
	{
		cin>>a[n]>>b[n]>>c[n]>>d[n];
		n++;
	}
	
	while(cin>>x>>y && !(x==9999.9 && y==9999.9))
	{
		bool f=0;
		cnt++;
		
		for(i=0;i<n;i++)
		{
			if(a[i]<x && x<c[i] && y<b[i] && d[i]<y)
			{
				f=1;
				cout<<"Point "<<cnt<<" is contained in figure "<<i+1<<"\n";
			}
		}
		
		if(!f)
			cout<<"Point "<<cnt<<" is not contained in any figure\n";
	}
	
	return 0;
}
