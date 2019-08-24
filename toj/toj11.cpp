#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
#include<memory.h>
#include<vector>
using namespace std;

int a[2000000],b[2000000];
long long loli=0;

void merge(int l,int r)
{
	int m=(l+r)/2,p=l,q=m+1,i;
	for(i=l;i<=r;i++)b[i]=a[i];
	for(i=l;i<=r;i++)
	{
		if((b[p]<=b[q]&&p<=m)||q>r)
		{
			a[i]=b[p];
			p++;
		}
		else
		{
			a[i]=b[q];
			loli+=q-i;
			q++;
		}
	}
}

void merge_sort(int l,int r)
{
	if(r>l)
	{
		int m=(l+r)/2;
		merge_sort(l,m);
		merge_sort(m+1,r);
		merge(l,r);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	merge_sort(0,n-1);
	cout<<loli<<'\n';
}
