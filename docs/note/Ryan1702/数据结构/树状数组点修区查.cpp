#include<bits/stdc++.h>
#define Maxn 500000
using namespace std;
int n,m;
int t[Maxn+5];
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
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		add(i,x);
	}
	for(int i=1;i<=m;i++)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int x,k;
			scanf("%d%d",&x,&k);
			add(x,k);
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",ask(y)-ask(x-1));
		}
	}
	return 0;
}
