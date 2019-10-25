#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int arr[100010],n,ouo;

inline bool check(int k)
{
	int i,s;
	int r=-999999999;
	
	for(i=0,s=0;i<n;i++)
	{
		if(r<arr[i])
		{
			r=arr[i]+k;
			s++;
		}
	}
	return s<=ouo; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    int t,p,q,m,i;
    cin>>t;
    
    while(t--)
    {
		cin>>ouo>>n;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n);
		p=0;
		q=(arr[n-1]-arr[0])/ouo+1;
		while(p<q)
		{
			m=(p+q)/2;
			if(check(m))
				q=m;
			else
				p=m+1;
		}
		cout<<fixed<<setprecision(1);
		cout<<p/2.0<<'\n';
	}
	
	return 0;
}
