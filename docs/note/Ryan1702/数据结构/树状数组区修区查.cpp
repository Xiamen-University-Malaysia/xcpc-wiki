#include<bits/stdc++.h>
#define Maxn 100000
using namespace std;
typedef long long ll;
int n,m;
ll t1[Maxn+5],t2[Maxn+5];
int lowbit(int x)
{
	return x&(-x);
}
void add(ll t[],int x,ll k)
{
	for(int i=x;i<=n;i+=lowbit(i)) t[i]+=k;
}
ll ask(ll t[],int x)
{
	ll ans=0;
	for(int i=x;i;i-=lowbit(i)) ans+=t[i];
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		ll x;
		scanf("%lld",&x);
		add(t1,i,x);
		add(t1,i+1,-x);
		add(t2,i,x*(i-1));
		add(t2,i+1,-x*i);
	}
	for(int i=1;i<=m;i++)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int x,y;
			ll k;
			scanf("%d%d%lld",&x,&y,&k);
			add(t1,x,k);
			add(t1,y+1,-k);
			add(t2,x,k*(x-1));
			add(t2,y+1,-k*y);
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",(ask(t1,y)*y-ask(t2,y))-(ask(t1,x-1)*(x-1)-ask(t2,x-1)));
		}
	}
	return 0;
}
