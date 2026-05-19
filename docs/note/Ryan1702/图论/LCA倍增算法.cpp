#include<bits/stdc++.h>
#define Maxn 1000000
using namespace std;
int n,m,root;
int head[Maxn+5],to[Maxn+5],nex[Maxn+5],w[Maxn+5],tot;
int f[35][Maxn+5],c[35][Maxn+5],dep[Maxn+5];
void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
}
void add(int x,int y,int z)
{
    to[++tot]=y;
    nex[tot]=head[x];
    w[tot]=z;
    head[x]=tot;
}
void dfs(int x,int fa)
{
    for(int i=1;i<31;i++)
    {
        f[i][x]=f[i-1][f[i-1][x]];
        c[i][x]=c[i-1][f[i-1][x]]+c[i-1][x];
    }
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==fa) continue;
        f[0][to[i]]=x;
        c[0][to[i]]=w[i];
        dep[to[i]]=dep[x]+1;
        dfs(to[i],x);
    }
}
pair<int,int> lca(int x,int y)
{
    if(dep[x]>dep[y]) swap(x,y);
    int tmp=dep[y]-dep[x];
    int cnt=0,ans=0;
    while(tmp)
    {
        if(tmp&1)
        {
            ans+=c[cnt][y];
            y=f[cnt][y];
        }
        tmp>>=1;
        cnt++;
    }
    if(x==y) return make_pair(x,ans);
    for(int i=30;i>=0;i--)
    {
        if(f[i][x]!=f[i][y])
        {
            ans+=c[i][x];
            x=f[i][x];
            ans+=c[i][y];
            y=f[i][y];
        }
    }
    ans+=c[0][x]+c[0][y];
    return make_pair(f[0][x],ans);
}
int main()
{
    scanf("%d%d%d",&n,&m,&root);
    init();
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    f[0][root]=root;
    dfs(root,-1);
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        pair<int,int> p=lca(x,y);
        printf("%d %d\n",p.first,p.second);
    }
    return 0;
}