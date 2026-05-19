#include<bits/stdc++.h>
#define Maxn 100000
using namespace std;
int head[Maxn+5],to[Maxn+5],nex[Maxn+5],w[Maxn+5],tot;
int d1[Maxn+5],d2[Maxn+5],up[Maxn+5],id[Maxn+5];
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
void dfs1(int x,int fa)
{
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==fa) continue;
        dfs1(to[i],x);
        if(d1[to[i]]+w[i]>d1[x])
        {
            d2[x]=d1[x];
            d1[x]=d1[to[i]]+w[i];
        }
        else if(d1[to[i]]+w[i]>d2[x]) d2[x]=d1[to[i]]+w[i];
    }
}
void dfs2(int x,int fa)
{
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==fa) continue;
        up[to[i]]=up[x]+w[i];
        if(d1[x]==d1[to[i]]+w[i]) up[to[i]]=max(up[to[i]],d2[x]+w[i]);
        else up[to[i]]=max(up[to[i]],d1[x]+w[i]);
        dfs2(to[i],x);
    }
}
int main()
{
    init();
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    int cnt=0,mn=1e9;
    for(int i=1;i<=n;i++)
    {
        if(max(d1[i],up[i])<mn)
        {
            id[0]=i;
            cnt=1;
            mn=max(d1[i],up[i]);
        }
        else if(max(d1[i],up[i])==mn)
        {
            id[cnt++]=i;
            mn=max(d1[i],up[i]);
        }
    }
    for(int i=0;i<cnt;i++) printf("%d ",id[i]);
    return 0;
}