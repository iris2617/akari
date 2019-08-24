#include<iostream>
#include<algorithm>
using namespace std;
typedef long long loli;

struct akari{
	int val,pri,s,aoi;
	akari *l,*r;
	akari(int k){
		pri=rand();
		aoi=val=k;
		l=0;
		r=0;
		s=1;
	}
	~akari()
	{
		if(l)
			delete l;
		if(r)
			delete r;
	}
	void up()
	{
		s=1;
		aoi=val;
		if(l)
		{
			s+=l->s;
			aoi=max(aoi,l->aoi);
		}
		if(r)
		{
			s+=r->s;
			aoi=max(aoi,r->aoi);
		}
	}
}*root;

int sana(akari *a)
{
	return a?a->s:0;
}

akari* merge(akari *a,akari *b)
{
	if(!a||!b)
	{
		return a?a:b; 
	}
	else
	{
		if(a->pri<b->pri)
		{
			a->r=merge(a->r,b);
			a->up();
			return a;
		}
		else
		{
			b->l=merge(a,b->l);
			b->up();
			return b;
		}
	}
}

void split(akari *node,akari *&a,akari *&b,int k)
{
	if(!node)
		a=b=0;
	else if(k<=sana(node->l))
	{ 
		b=node;
		split(node->l,a,b->l,k);
		b->up();
	}
	else 
	{
		a=node;
		split(node->r,a->r,b,k-sana(node->l)-1);
		a->up();
	}
	return;
}
 
void change(int x,int y)
{
	akari *a,*b,*c,*d;
	split(root,a,d,x-1);
	split(d,b,c,1);
	b->val=y;
	b->up();
	root=merge(a,merge(b,c));
	return;
}

void insert(int x,int y)
{
	akari *a,*b;
	split(root,a,b,x-1);
	root=merge(a,merge(new akari(y),b));
	return;
}

int query(int x,int y)
{
	int ans;
	akari *a,*b,*c;
	split(root,a,b,x-1);
	split(b,b,c,y-x+1);
	ans=b->aoi;
	root=merge(a,merge(b,c));
	return ans;
}

void del(int x)
{
	akari *a,*b,*c;
	split(root,a,b,x-1);
	split(b,b,c,1);
	root=merge(a,c);
	delete b;
	return;
}

int main(){ 
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	srand(12345678);
	int n,q,i,type,x,y;
	while(cin>>n>>q)
	{
		delete root;
		root=0;
		for(i=0;i<n;i++)
		{
			cin>>x;
			root=merge(root,new akari(x));
		}
		while(q--)
		{
			cin>>type;
			if(type==1)
			{
				cin>>x>>y;
				change(x,y);
			}
			else if(type==2)
			{
				cin>>x>>y;
				if(x>y)
					swap(x,y);
				cout<<query(x,y)<<'\n';
			}
			else if(type==3)
			{
				cin>>x>>y;
				insert(x,y);
			}
			else
			{
				cin>>x;
				del(x);
			}
		}
	}
	
	return 0;
}
