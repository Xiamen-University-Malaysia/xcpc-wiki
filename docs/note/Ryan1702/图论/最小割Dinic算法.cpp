#include<bits/stdc++.h>
#define Maxn 32
#define Maxm 2000
#define Mod 10000
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],tot;
int cur[Maxn+5];
int d[Maxn+5];
ll w[Maxm+5];
int n,m,s=1;
pair<int,int> v[Maxm+5];
bool vis[Maxn+5];
void init()
{
    memset(head,-1,sizeof(head));
    tot=1;
}
void add(int x,int y,ll z)
{
    to[++tot]=y;
    w[tot]=z;
    nex[tot]=head[x];
    head[x]=tot;
}
bool bfs()
{
    memset(d,0,sizeof(d));
    queue<int> q;
    q.push(s);
    d[s]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=head[x];i!=-1;i=nex[i])
        {
            if(d[to[i]]==0&&w[i])
            {
                d[to[i]]=d[x]+1;
                q.push(to[i]);
                if(to[i]==n) return true;
            }
        }
    }
    return false;
}
ll dfs(int x,ll mf)
{
    if(x==n) return mf;
    ll sum=0;
    for(int i=cur[x];i!=-1;i=nex[i])
    {
        cur[x]=i;
        if(d[x]+1==d[to[i]]&&w[i])
        {
            ll f=dfs(to[i],min(mf,w[i]));
            w[i]-=f;
            w[i^1]+=f;
            mf-=f;
            sum+=f;
            if(mf==0) break;
        }
    }
    if(sum==0) d[x]=0;
    return sum;
}
ll dinic()
{
    ll flow=0;
    while(bfs())
    {
        memcpy(cur,head,sizeof(head));
        flow+=dfs(s,INF);
    }
    return flow;
}
void cal(int x)
{
    vis[x]=true;
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(!vis[to[i]]&&w[i]) cal(to[i]);
    }
}
int main()
{
    init();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        ll z;
        scanf("%d%d%lld",&x,&y,&z);
        add(x,y,z*Mod+1);
        add(y,x,0);
    }
    ll ans=dinic();
    printf("%lld %lld\n",ans/Mod,ans%Mod);
    /*
    memset(vis,0,sizeof(vis));
    cal(s);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) printf("%d ",i);
    }
    puts("");
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) printf("%d ",i);
    }
    */
    return 0;
}
