#include<iostream>
using namespace std;
void merge_sort(int[],int[],int,int);
void merge(int[],int[],int,int,int);
void merge_sort(int c[],int d[],int p,int q)
{
	if(p<q)
	{
		int m=(p+q)/2;
		merge_sort(c,d,p,m);
		merge_sort(c,d,m+1,q);
		merge(c,d,p,m,q);
	}
}
void merge(int c[],int d[],int p,int m,int q)
{
	int x,i=p,j=m+1;
	for(x=p;x<=q;x++)d[x]=c[x];
	for(x=p;x<=q;x++)
	{
		if(i>m)
			c[x]=d[j++];
		else if(j>q)
			c[x]=d[i++];
		else
		{
			if(d[i]>d[j])
				c[x]=d[j++];
			else
				c[x]=d[i++];
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,x,s,p,q,m,h;
	cin>>n;
	int c[n],d[n];
	for(x=0;x<n;x++)cin>>c[x];
	merge_sort(c,d,0,n-1);
	double o;
	cin>>s;
	while(s--)
	{
		cin>>o;
		h=0;
		if(o==c[0]||o==c[n-1])
			cout<<o<<"\n";
		else if(o<c[0])
			cout<<"no "<<c[0]<<"\n";
		else if(o>c[n-1])
			cout<<c[n-1]<<" no\n";
		else
		{
			p=0,q=n-1;
			while(p+1<q)
			{
				m=(p+q)/2;
				if(o==c[m])
				{
					cout<<o<<"\n";
					goto hi;
				}
				else if(o<c[m])
					q=m;
				else
					p=m;
			}
			cout<<c[p]<<" "<<c[q]<<"\n";
			hi:
				s=s;
		} 
	}
}
