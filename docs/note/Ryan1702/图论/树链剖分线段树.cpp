#include<bits/stdc++.h>
#define Maxn 100000
#define Maxm 200000
using namespace std;
typedef long long ll;
struct node
{
    int l,r;
    ll sum,lazy;
}tr[Maxn<<2];
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],tot;
int fa[Maxn+5],siz[Maxn+5],dep[Maxn+5];
int son[Maxn+5],top[Maxn+5];
int dfn[Maxn+5],rnk[Maxn+5],t;
ll arr[Maxn+5],a[Maxn+5];
int n,m,root;
ll Mod;
void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
}
void add(int x,int y)
{
    to[++tot]=y;
    nex[tot]=head[x];
    head[x]=tot;
}
void dfs1(int x,int f)
{
    fa[x]=f;
    siz[x]=1;
    dep[x]=dep[f]+1;
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==f) continue;
        dfs1(to[i],x);
        siz[x]+=siz[to[i]];
        if(siz[son[x]]<siz[to[i]]) son[x]=to[i];
    }
}
void dfs2(int x,int f)
{
    top[x]=f;
    dfn[x]=++t;
    rnk[t]=x;
    if(son[x]) dfs2(son[x],f);
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]!=fa[x]&&to[i]!=son[x]) dfs2(to[i],to[i]);
    }
}
void pushup(int p)
{
    tr[p].sum=(tr[p<<1].sum+tr[p<<1|1].sum)%Mod;
}
void pushdown(int p)
{
    if(tr[p].lazy)
    {
        ll k=tr[p].lazy;
        tr[p<<1].sum=(tr[p<<1].sum+(tr[p<<1].r-tr[p<<1].l+1)*k%Mod)%Mod;
        tr[p<<1|1].sum=(tr[p<<1|1].sum+(tr[p<<1|1].r-tr[p<<1|1].l+1)*k%Mod)%Mod;
        tr[p<<1].lazy=(tr[p<<1].lazy+k)%Mod;
        tr[p<<1|1].lazy=(tr[p<<1|1].lazy+k)%Mod;
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
void update(int p,int l,int r,ll k)
{
    if(l<=tr[p].l&&tr[p].r<=r)
    {
        tr[p].sum=(tr[p].sum+(tr[p].r-tr[p].l+1)*k%Mod)%Mod;
        tr[p].lazy=(tr[p].lazy+k)%Mod;
        return ;
    }
    int mid=(tr[p].l+tr[p].r)>>1;
    pushdown(p);
    if(l<=mid) update(p<<1,l,r,k);
    if(r>mid) update(p<<1|1,l,r,k);
    pushup(p);
}
ll query(int p,int l,int r)
{
    if(l<=tr[p].l&&tr[p].r<=r) return tr[p].sum;
    int mid=(tr[p].l+tr[p].r)>>1;
    pushdown(p);
    ll sum=0;
    if(l<=mid) sum=(sum+query(p<<1,l,r))%Mod;
    if(r>mid) sum=(sum+query(p<<1|1,l,r))%Mod;
    return sum;
}
int main()
{
    init();
    scanf("%d%d%d%lld",&n,&m,&root,&Mod);
    for(int i=1;i<=n;i++) scanf("%lld",arr+i);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs1(root,0);
    dfs2(root,root);
    for(int i=1;i<=n;i++) a[i]=arr[rnk[i]]%Mod;
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int x,y;
            ll z;
            scanf("%d%d%lld",&x,&y,&z);
            z%=Mod;
            while(top[x]!=top[y])
            {
                if(dep[top[x]]<dep[top[y]]) swap(x,y);
                update(1,dfn[top[x]],dfn[x],z);
                x=fa[top[x]];
            }
            if(dep[x]>dep[y]) swap(x,y);
            update(1,dfn[x],dfn[y],z);
        }
        else if(op==2)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            ll sum=0;
            while(top[x]!=top[y])
            {
                if(dep[top[x]]<dep[top[y]]) swap(x,y);
                sum=(sum+query(1,dfn[top[x]],dfn[x]))%Mod;
                x=fa[top[x]];
            }
            if(dep[x]>dep[y]) swap(x,y);
            sum=(sum+query(1,dfn[x],dfn[y]))%Mod;
            printf("%lld\n",sum);
        }
        else if(op==3)
        {
            int x;
            ll z;
            scanf("%d%lld",&x,&z);
            z%=Mod;
            update(1,dfn[x],dfn[x]+siz[x]-1,z);
        }
        else
        {
            int x;
            scanf("%d",&x);
            printf("%lld\n",query(1,dfn[x],dfn[x]+siz[x]-1));
        }
    }
    return 0;
}