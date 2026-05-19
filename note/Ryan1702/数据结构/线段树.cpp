#include<bits/stdc++.h>
#define Maxn 100000
using namespace std;
typedef long long ll;
struct node
{
	int l,r;
	ll sum,lazy;
}tr[Maxn<<2];
ll a[Maxn+5];
void pushup(int p)
{
	tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
}
void pushdown(int p)
{
	if(tr[p].lazy)
	{
		ll k=tr[p].lazy;
		tr[p<<1].sum+=(tr[p<<1].r-tr[p<<1].l+1)*k;
		tr[p<<1|1].sum+=(tr[p<<1|1].r-tr[p<<1|1].l+1)*k;
		tr[p<<1].lazy+=k;
		tr[p<<1|1].lazy+=k;
		tr[p].lazy=0;
	}
}
void build(int p,int l,int r)
{
	tr[p]={l,r,a[l],0};
	if(l==r) return ;
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pushup(p);
}
ll query(int p,int x,int y)
{
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p].sum;
	int mid=(tr[p].l+tr[p].r)>>1;
	ll sum=0;
	pushdown(p);
	if(x<=mid) sum+=query(p<<1,x,y);
	if(y>mid) sum+=query(p<<1|1,x,y);
	return sum;
}
void modify(int p,int x,int y,ll k)
{
	if(x<=tr[p].l&&tr[p].r<=y)
	{
		tr[p].sum+=(tr[p].r-tr[p].l+1)*k;
		tr[p].lazy+=k;
		return ;
	}
	int mid=(tr[p].l+tr[p].r)>>1;
	pushdown(p);
	if(x<=mid) modify(p<<1,x,y,k);
	if(y>mid) modify(p<<1|1,x,y,k);
	pushup(p);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	build(1,1,n);
	while(m--)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int x,y;
			ll k;
			scanf("%d%d%lld",&x,&y,&k);
			modify(1,x,y,k);
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(1,x,y));
		}
	}
	return 0;
}
