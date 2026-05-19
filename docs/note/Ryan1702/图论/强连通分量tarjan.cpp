#include<bits/stdc++.h>
#define Maxn 10000
#define Maxm 50000
using namespace std;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],tot;
int dfn[Maxn+5],low[Maxn+5];
int st[Maxn+5],sz,t;
bool in[Maxn+5];
int scc[Maxn+5],sccsiz[Maxn+5],cnt;
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
void tarjan(int x)
{
    dfn[x]=low[x]=++t;
    st[++sz]=x;
    in[x]=true;
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(!dfn[to[i]])
        {
            tarjan(to[i]);
            low[x]=min(low[x],low[to[i]]);
        }
        else if(in[to[i]]) low[x]=min(low[x],dfn[to[i]]);
    }
    if(dfn[x]==low[x])
    {
        int y;
        cnt++;
        do
        {
            y=st[sz--];
            in[y]=false;
            scc[x]=cnt;
            sccsiz[cnt]++;
        }while(x!=y);
    }
}
int main()
{
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i]) tarjan(i);
    }
    int ans=0;
    for(int i=1;i<=cnt;i++) ans+=sccsiz[i]>1?1:0;
    printf("%d\n",ans);
    return 0;
}