#include<bits/stdc++.h>
#define Maxn 100000
#define Maxm 200000
#define INF 1e9
using namespace std;
int n,m,s;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],w[Maxm+5],tot;
int dis[Maxn+5],pre[Maxn+5];
bool vis[Maxn+5];
priority_queue<pair<int,int>> q;
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
void path(int x)
{
    if(x==s)
    {
        printf("%d ",s);
        return ;
    }
    path(pre[x]);
    printf("%d ",x);
}
void dij(int s)
{
    q.push(make_pair(0,s));
    memset(vis,0,sizeof(vis));
    memset(dis,127,sizeof(dis));
    dis[s]=0;
    while(!q.empty())
    {
        int x=q.top().second;
        q.pop();
        if(vis[x]) continue;
        vis[x]=true;
        for(int i=head[x];i!=-1;i=nex[i])
        {
            if(dis[x]+w[i]<dis[to[i]])
            {
                dis[to[i]]=dis[x]+w[i];
                pre[to[i]]=x;
                q.push(make_pair(-dis[to[i]],to[i]));
            }
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",dis[i]);
    /*
    for(int i=1;i<=n;i++)
    {
        path(i);
        puts("");
    }
    */
}
int main()
{
    init();
    scanf("%d%d%d",&n,&m,&s);
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }
    dij(s);
    return 0;
}