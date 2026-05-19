#include<bits/stdc++.h>
#define Maxn 1000000
#define Maxm 2000000
using namespace std;
int n;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],tot;
int dep[Maxn+5],siz[Maxn+5],son[Maxn+5];
int d[Maxn+5];
set<int> s;
struct node
{
    int l,r,lazy;
    pair<int,int> mx;
}tr[Maxn<<2];
void pushup(int p)
{
    tr[p].mx=max(tr[p<<1].mx,tr[p<<1|1].mx);
}
void pushdown(int p)
{
    if(tr[p].lazy)
    {
        int k=tr[p].lazy;
        tr[p<<1].mx.first+=k;
        tr[p<<1|1].mx.first+=k;
        tr[p<<1].lazy+=k;
        tr[p<<1|1].lazy+=k;
        tr[p].lazy=0;
    }
}
void build(int p,int l,int r)
{
    tr[p].l=l;
    tr[p].r=r;
    tr[p].lazy=0;
    tr[p].mx.first=0;
    tr[p].mx.second=-l;
    if(l==r) return ;
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    pushup(p);
}
void update(int p,int l,int r,int k)
{
    if(l<=tr[p].l&&tr[p].r<=r)
    {
        tr[p].mx.first+=k;
        tr[p].lazy+=k;
        return ;
    }
    pushdown(p);
    int mid=(tr[p].l+tr[p].r)>>1;
    if(l<=mid) update(p<<1,l,r,k);
    if(r>mid) update(p<<1|1,l,r,k);
    pushup(p);
}
pair<int,int> query(int p,int l,int r)
{
    if(l<=tr[p].l&&tr[p].r<=r)
    {
        return tr[p].mx;
    }
    pair<int,int> ans=make_pair(0,0);
    pushdown(p);
    int mid=(tr[p].l+tr[p].r)>>1;
    if(l<=mid) ans=max(ans,query(p<<1,l,r));
    if(r>mid) ans=max(ans,query(p<<1|1,l,r));
    return ans;
}
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
    dep[x]=dep[f]+1;
    siz[x]=1;
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==f) continue;
        dfs1(to[i],x);
        siz[x]+=siz[to[i]];
        if(siz[to[i]]>siz[son[x]]) son[x]=to[i];
    }
}
void selfsub(int x,int f,int sn)
{
    update(1,dep[x],dep[x],1);
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==f||to[i]==sn) continue;
        selfsub(to[i],x,sn);
    }
}
void cut(int x,int f)
{
    update(1,dep[x],dep[x],-1);
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==f) continue;
        cut(to[i],x);
    }
}
void dfs2(int x,int f,int op)
{
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==f||to[i]==son[x]) continue;
        dfs2(to[i],x,1);
    }
    if(son[x]) dfs2(son[x],x,0);
    selfsub(x,f,son[x]);
    d[x]=-query(1,1,n).second-dep[x];
    if(op) cut(x,f);
}
int main()
{
    init();
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    build(1,1,n);
    dfs1(1,0);
    dfs2(1,0,0);
    for(int i=1;i<=n;i++) printf("%d\n",d[i]);
    return 0;
}