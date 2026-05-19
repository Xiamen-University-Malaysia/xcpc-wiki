#include<bits/stdc++.h>
#define Maxn 1000000
using namespace std;
int n;
int head[Maxn+5],to[Maxn+5],nex[Maxn+5],w[Maxn+5],tot;
int siz[Maxn+5],dp[Maxn+5],a[Maxn+5];
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
    siz[x]=1;
    dp[x]=0;
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==fa) continue;
        dfs1(to[i],x);
        siz[x]+=siz[to[i]];
        dp[x]+=dp[to[i]]+siz[to[i]];
    }
}
void dfs2(int x,int fa)
{
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==fa) continue;
        dp[to[i]]=dp[x]-siz[to[i]]+(n-siz[to[i]]);
        dfs2(to[i],x);
    }
}
int main()
{
    scanf("%d",&n);
    init();
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    int mn=1e9,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(dp[i]<mn)
        {
            a[0]=i;
            cnt=1;
            mn=dp[i];
        }
        else if(dp[i]==mn)
        {
            a[cnt++]=i;
        }
    }
    for(int i=0;i<cnt;i++) printf("%d ",a[i]);
    return 0;
}