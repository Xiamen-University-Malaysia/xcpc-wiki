#include<bits/stdc++.h>
#define Maxn 100000
#define Maxm 200000
using namespace std;
typedef long long ll;
int head[Maxn+5],nex[Maxm+5],to[Maxm+5],tot;
int siz[Maxn+5],son[Maxn+5];
int col[Maxn+5],cnt[Maxn+5];
ll ans[Maxn+5];
int mx;
ll sum;
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
    siz[x]=1;
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==f) continue;
        dfs1(to[i],x);
        siz[x]+=siz[to[i]];
        if(siz[son[x]]<siz[to[i]]) son[x]=to[i];
    }
}
void self_sub(int x,int f,int s)
{
    cnt[col[x]]++;
    if(mx<cnt[col[x]])
    {
        mx=cnt[col[x]];
        sum=col[x];
    }
    else if(mx==cnt[col[x]]) sum+=col[x];
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==f||to[i]==s) continue;
        self_sub(to[i],x,s);
    }
}
void cut(int x,int f)
{
    cnt[col[x]]--;
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
    self_sub(x,f,son[x]);
    ans[x]=sum;
    if(op)
    {
        cut(x,f);
        mx=0;
        sum=0;
    }
}
int main()
{
    int n;
    init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",col+i);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs1(1,0);
    dfs2(1,0,0);
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
    puts("");
    return 0;
}