#include<bits/stdc++.h>
#define Maxn 1000000
using namespace std;
int head[Maxn+5],to[Maxn+5],nex[Maxn+5],tot;
bool vis[Maxn+5];
int fa[Maxn+5],ans[Maxn+5];
vector<pair<int,int> > q[Maxn+5];
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
int Find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=Find(fa[x]);
}
void tarjan(int x)
{
    vis[x]=true;
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(vis[to[i]]) continue;
        tarjan(to[i]);
        fa[to[i]]=x;
    }
    for(int i=0;i<q[x].size();i++)
    {
        if(vis[q[x][i].first]) ans[q[x][i].second]=Find(q[x][i].first);
    }
}
int main()
{
    init();
    int n,m,s;
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        q[x].push_back(make_pair(y,i));
        q[y].push_back(make_pair(x,i));
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    tarjan(s);
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}