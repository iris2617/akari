#include<iostream>
using namespace std;

int used[10010],sana[10010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int z,i,m,l,t,cnt=0;
	
	while(cin>>z>>i>>m>>l && z && i && m && l)
	{
		cnt++;
		t=0;
		while(used[l]!=cnt)
		{
			used[l]=cnt;
			sana[l]=t++;
			l=(z*l+i)%m;
		}
		cout<<"Case "<<cnt<<": "<<t-sana[l]<<'\n';
	}
	
	return 0;
}
