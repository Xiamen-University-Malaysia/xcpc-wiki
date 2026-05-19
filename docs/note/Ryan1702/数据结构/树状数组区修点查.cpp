#include<bits/stdc++.h>
#define Maxn 500000
using namespace std;
int n,m;
int a[Maxn+5],t[Maxn+5];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int k)
{
	for(int i=x;i<=n;i+=lowbit(i)) t[i]+=k;
}
int ask(int x)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i)) ans+=t[i];
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=m;i++)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			add(x,k);
			add(y+1,-k);
		}
		else
		{
			int x;
			scanf("%d",&x);
			printf("%d\n",a[x]+ask(x));
		}
	}
	return 0;
}
