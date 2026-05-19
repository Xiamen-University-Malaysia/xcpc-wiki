#include<bits/stdc++.h>
#define Maxn 5000
#define Maxm 100000
#define INF 0x3f3f3f3f
using namespace std;
int n,m,s,t;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],tot;
int w[Maxm+5],cost[Maxm+5];
int dis[Maxn+5],mf[Maxn+5],pre[Maxn+5];
bool vis[Maxn+5];
void init()
{
    memset(head,-1,sizeof(head));
    tot=1;
}
void add(int x,int y,int z,int c)
{
    to[++tot]=y;
    w[tot]=z;
    cost[tot]=c;
    nex[tot]=head[x];
    head[x]=tot;
}
bool spfa()
{
    memset(dis,0x3f,sizeof(dis));
    memset(mf,0,sizeof(mf));
    memset(vis,0,sizeof(vis));
    queue<int> q;
    dis[s]=0;
    mf[s]=INF;
    vis[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=false;
        for(int i=head[x];i!=-1;i=nex[i])
        {
            if(dis[to[i]]>dis[x]+cost[i]&&w[i])
            {
                dis[to[i]]=dis[x]+cost[i];
                mf[to[i]]=min(mf[x],w[i]);
                pre[to[i]]=i;
                if(!vis[to[i]])
                {
                    q.push(to[i]);
                    vis[to[i]]=true;
                }
            }
        }
    }
    return mf[t]>0;
}
int flow=0,c=0;
void ek()
{
    while(spfa())
    {
        int v=t;
        while(v!=s)
        {
            int i=pre[v];
            w[i]-=mf[t];
            w[i^1]+=mf[t];
            v=to[i^1];
        }
        flow+=mf[t];
        c+=mf[t]*dis[t];
    }
}
int main()
{
    init();
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++)
    {
        int x,y,z,c;
        scanf("%d%d%d%d",&x,&y,&z,&c);
        add(x,y,z,c);
        add(y,x,0,-c);
    }
    ek();
    printf("%d %d\n",flow,c);
    return 0;
}
