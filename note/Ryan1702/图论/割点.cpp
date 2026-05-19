#include<bits/stdc++.h>
#define Maxn 20000
#define Maxm 200000
using namespace std;
int n,m,root;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],tot;
int dfn[Maxn+5],low[Maxn+5],t;
bool cut[Maxn+5];
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
    int child=0;
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(!dfn[to[i]])
        {
            tarjan(to[i]);
            low[x]=min(low[x],low[to[i]]);
            if(low[to[i]]>=dfn[x])
            {
                child++;
                if(x!=root||child>1) cut[x]=true;
            }
        }
        else low[x]=min(low[x],dfn[to[i]]);
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
        if(!dfn[i])
        {
            root=i;
            tarjan(i);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(cut[i]) ans++;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
    {
        if(cut[i]) printf("%d ",i);
    }
    return 0;
}