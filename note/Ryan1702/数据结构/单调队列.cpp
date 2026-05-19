#include<bits/stdc++.h>
#define Maxn 1000000
using namespace std;
int a[Maxn+5],q[Maxn+5];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	int h=1,t=0;
	for(int i=1;i<=n;i++)
	{
		while(h<=t&&a[q[t]]>=a[i]) t--;
		q[++t]=i;
		if(q[h]<i-m+1) h++;
		if(i>=m) printf("%d ",a[q[h]]);
	}
	puts("");
	h=1;
	t=0;
	for(int i=1;i<=n;i++)
	{
		while(h<=t&&a[q[t]]<=a[i]) t--;
		q[++t]=i;
		if(q[h]<i-m+1) h++;
		if(i>=m) printf("%d ",a[q[h]]);
	}
	return 0;
}
