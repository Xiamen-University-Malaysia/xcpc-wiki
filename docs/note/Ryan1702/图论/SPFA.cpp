#include<bits/stdc++.h>
#define Maxn 100000
#define Maxm 200000
using namespace std;
int n,m,s;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],w[Maxm+5],tot;
int dis[Maxn+5],cnt[Maxn+5];
bool vis[Maxn+5];
queue<int> q;
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
bool spfa(int s)
{
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    q.push(s);
    vis[s]=true;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=false;
        for(int i=head[x];i!=-1;i=nex[i])
        {
            if(dis[x]+w[i]<dis[to[i]])
            {
                dis[to[i]]=dis[x]+w[i];
                cnt[to[i]]=cnt[x]+1;
                if(cnt[to[i]]>=n) return false;
                if(!vis[to[i]])
                {
                    q.push(to[i]);
                    vis[to[i]]=true;
                }
            }
        }
    }
    return true;
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
    if(spfa(s))
    {
        for(int i=1;i<=n;i++) printf("%d ",dis[i]);
    }
    return 0;
}