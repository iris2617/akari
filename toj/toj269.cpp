#include<iostream>
using namespace std;

int main() {
	int n,a,ans=-1e9;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		ans=max(ans,a);
	}
	printf("%d\n",ans);
	return 0;
}
