#include<iostream>
using namespace std;

int rc[6000][6000],qq[6000][6000],n,m;

int queryb(int a,int b)
{
    if(b==0)
        return 0;
    return rc[a][b]+queryb(a,b-(b&-b));
}
int querya(int a,int b)
{
    if(a==0)
        return 0;
    return querya(a-(a&-a),b)+queryb(a,b);
}
void addi(int a,int b,int c)
{
    if(a<=n&&b<=m)
    {
        rc[a][b]+=c;
        addi(a+(a&-a),b,c);
    }
}
void add(int a,int b,int c)
{
    if(a<=n&&b<=m)
    {
        rc[a][b]+=c;
        add(a,b+(b&-b),c);
        addi(a+(a&-a),b,c);
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i,j,a,b,c,d,q;
    char ch;
    //input
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>rc[i][j];
            qq[i][j]=rc[i][j];
        }
    }
    //setBIT
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m-1;j++)
        {
            rc[i][j+(j&-j)]+=rc[i][j];
//            if(j+(j&-j)>m)cout<<'*';
        }
    }
    for(j=1;j<=m;j++)
    {
        for(i=1;i<=n-1;i++)
        {
            rc[i+(i&-i)][j]+=rc[i][j];
//            if(i+(i&-i)>n)cout<<i<<'\n';
        }
    }
    //query
    cin>>q;
    while(q--)
    {
        cin>>ch;
        if(ch=='Q')
        {
            cin>>a>>b>>c>>d;
            if(a>c)swap(a,c);
            if(b>d)swap(b,d);
            cout<<querya(a-1,b-1)+querya(c,d)-querya(a-1,d)-querya(c,b-1)<<'\n';
        }
        else
        {
            cin>>a>>b>>c;
            d=c-qq[a][b];
            qq[a][b]=c;
            add(a,b,d);
        }
    }
    return 0;
}
