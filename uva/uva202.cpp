#include<iostream>
using namespace std;

int used[30010],sana[30010],cycle[3010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int x,y,gg,a,b,c,r,i;
	int cnt=0,t;
	
	while(cin>>x>>y)
	{
		cnt++;
		
		gg=x/y;
		r=x%y;
		t=0;
		while(used[r]!=cnt)
		{
			used[r]=cnt;
			sana[r]=t;
			cycle[t]=(r*10)/y;
			r=(r*10)%y;
			t++;
		}
		
		if(t>50)
		{
			sana[r]=0;
		}
		
		cout<<x<<"/"<<y<<" = "<<gg<<'.';
		
		for(i=0;i<min(t,50);i++)
		{
			if(i==sana[r])
				cout<<'(';
			cout<<cycle[i];
		}
		
		if(t>50)
		{
			cout<<"...";
		}
		
		cout<<")\n";
		cout<<"   "<<t-sana[r]<<" = number of digits in repeating cycle\n\n";
	}
	
	return 0;
}
