#include<bits/stdc++.h>
#define Maxn 500000
#define Maxm 1000000
using namespace std;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],tot;
int fa[Maxn+5],son[Maxn+5],dep[Maxn+5],siz[Maxn+5];
int top[Maxn+5];
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
    dep[x]=dep[f]+1;
    siz[x]=1;
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
    if(son[x]) dfs2(son[x],f);
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]!=fa[x]&&to[i]!=son[x]) dfs2(to[i],to[i]);
    }
}
int lca(int x,int y)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]>dep[top[y]]) x=fa[top[x]];
        else y=fa[top[y]];
    }
    return dep[x]<dep[y]?x:y;
}
int main()
{
    int n,m,s;
    init();
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs1(s,0);
    dfs2(s,s);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",lca(x,y));
    }
    return 0;
}