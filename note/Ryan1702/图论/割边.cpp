#include<bits/stdc++.h>
#define Maxn 50000
#define Maxm 600000
using namespace std;
int n,m;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],tot;
int dfn[Maxn+5],low[Maxn+5],t;
bool bri[Maxm+5];
void init()
{
    memset(head,-1,sizeof(head));
    tot=1;
}
void add(int x,int y)
{
    to[++tot]=y;
    nex[tot]=head[x];
    head[x]=tot;
}
void tarjan(int x,int j)
{
    dfn[x]=low[x]=++t;
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(!dfn[to[i]])
        {
            tarjan(to[i],i);
            low[x]=min(low[x],low[to[i]]);
            if(low[to[i]]>dfn[x]) bri[i]=true;
        }
        else if(i!=(j^1)) low[x]=min(low[x],dfn[to[i]]);
    }
}
int main()
{
    init();
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i]) tarjan(i,0);
    }
    int ans=0;
    for(int i=2;i<=tot;i++)
    {
        if(bri[i]) ans++;
    }
    printf("%d\n",ans);
    return 0;
}