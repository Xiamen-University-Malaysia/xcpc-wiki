#include<bits/stdc++.h>
#define Maxn 100
#define Maxm 10000
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],w[Maxm+5],tot;
bool vis[Maxn+5];
int h[Maxn+5];
int dis[Maxn+5][Maxn+5];
queue<int> q;
priority_queue<pair<int,int>> pq;
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
void spfa(int s)
{
    while(!q.empty()) q.pop();
    memset(vis,0,sizeof(vis));
    memset(h,0x3f,sizeof(h));
    h[s]=0;
    vis[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=false;
        for(int i=head[x];i!=-1;i=nex[i])
        {
            if(h[x]+w[i]<h[to[i]])
            {
                h[to[i]]=h[x]+w[i];
                if(!vis[to[i]])
                {
                    q.push(to[i]);
                    vis[to[i]]=true;
                }
            }
        }
    }
}
void dij(int s)
{
    while(!pq.empty()) pq.pop();
    memset(vis,0,sizeof(vis));
    pq.push(make_pair(0,s));
    dis[s][s]=0;
    while(!pq.empty())
    {
        int x=pq.top().second;
        pq.pop();
        if(vis[x]) continue;
        vis[x]=true;
        for(int i=head[x];i!=-1;i=nex[i])
        {
            if(dis[s][x]+w[i]<dis[s][to[i]])
            {
                dis[s][to[i]]=dis[s][x]+w[i];
                pq.push(make_pair(-dis[s][to[i]],to[i]));
            }
        }
    }
}
int main()
{
    init();
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    for(int i=1;i<=n;i++) add(0,i,0);
    spfa(0);
    for(int i=1;i<=n;i++)
    {
        for(int j=head[i];j!=-1;j=nex[j])
        {
            w[j]+=h[i]-h[to[j]];
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++) dij(i);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dis[i][j]==INF)  printf("inf ");
            else printf("%d ",dis[i][j]-h[i]+h[j]);
        }
        puts("");
    }
    return 0;
}