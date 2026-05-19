#include<bits/stdc++.h>
#define Maxn 1000000
using namespace std;
int head[Maxn+5],to[Maxn+5],nex[Maxn+5],w[Maxn+5],tot;
int siz[Maxn+5],wei[Maxn+5],ans[Maxn+5];
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
    siz[x]=1;
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==fa) continue;
        dfs(to[i],x);
        siz[x]+=siz[to[i]];
        wei[x]=max(wei[x],siz[to[i]]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    init();
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    dfs(1,-1);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(max(wei[i],n-siz[i])<=n/2)
        {
            ans[cnt++]=i;
        }
    }
    for(int i=0;i<cnt;i++) printf("%d ",ans[i]);
    return 0;
}