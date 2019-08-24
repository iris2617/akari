#include<iostream>
#include<cmath>
#include<algorithm>
#define loli long long
#define akari 100
#define sagiri 1000000009
using namespace std;

loli ouo[1000010],qwq[1000010];

loli nanahira(loli laur)
{
	loli a=1,b=akari;
	while(laur>0)
	{
		if(laur&1)
		{
			a=(a*b)%sagiri;
		}
		b=(b*b)%sagiri;
		laur>>=1;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s,t;
	loli a,b,i,j,va,vb,x,k,w,p,q,m,aoi;
	loli milos;
	double answer;
	cin>>s>>t>>k>>x;
	a=s.size();
	b=t.size();
	milos=nanahira(k-1);
	
	for(i=0,va=0;i<a;i++)
	{
		if(i>=k)
		{
			va=(va-(s[i-k]-'a')*milos+sagiri)%sagiri;
		}
		va=(va*akari+s[i]-'a')%sagiri;
		if(i>=k-1)
		{
			ouo[i-k+1]=va;
		}
	}
	for(i=0,vb=0;i<b;i++)
	{
		if(i>=k)
		{
			vb=(vb-(t[i-k]-'a')*milos+sagiri)%sagiri;
		}
		vb=(vb*akari+t[i]-'a')%sagiri;
		if(i>=k-1)
		{
			qwq[i-k+1]=vb;
		}
	}
	sort(ouo,ouo+a-k+1);
	sort(qwq,qwq+b-k+1);
	//
	for(i=0,answer=0;i<b-k+1;i++)
	{
		for(p=0,q=a-k;p<q;)
		{
			m=(p+q)/2;
			if(qwq[i]<ouo[m])
				q=m;
			else
				p=m+1;
		}
		aoi=p;
		for(p=0,q=a-k;p<q;)
		{
			m=(p+q)/2;
			if(qwq[i]<=ouo[m])
				q=m;
			else
				p=m+1;
		}
		if(aoi-p>x)
			answer++;
	}
	//
	if(answer/(b-k+1)>0.1)
		cout<<"copy dog!\n";
	else
		cout<<"innocent!\n";
	
	return 0;
}

