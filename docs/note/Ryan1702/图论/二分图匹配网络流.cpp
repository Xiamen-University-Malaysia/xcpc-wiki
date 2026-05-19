#include<bits/stdc++.h>
#define Maxn 1000
#define Maxm 102000
#define INF 0x3f3f3f3f
using namespace std;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],tot;
int cur[Maxn+5];
int w[Maxm+5];
int d[Maxn+5];
int n,m,e,s,t;
void init()
{
    memset(head,-1,sizeof(head));
    tot=1;
}
void add(int x,int y,int z)
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
                if(to[i]==t) return true;
            }
        }
    }
    return false;
}
int dfs(int x,int mf)
{
    if(x==t) return mf;
    int sum=0;
    for(int i=cur[x];i!=-1;i=nex[i])
    {
        cur[x]=i;
        if(d[to[i]]==d[x]+1&&w[i])
        {
            int f=dfs(to[i],min(mf,w[i]));
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
int main()
{
    init();
    scanf("%d%d%d",&n,&m,&e);
    s=1;
    t=n+m+2;
    for(int i=2;i<=n+1;i++)
    {
        add(1,i,1);
        add(i,1,0);
    }
    for(int i=1;i<=e;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(1+x,1+n+y,1);
        add(1+n+y,1+x,0);
    }
    for(int i=n+2;i<=n+m+1;i++)
    {
        add(i,n+m+2,1);
        add(n+m+2,i,0);
    }
    int ans=0;
    while(bfs())
    {
        memcpy(cur,head,sizeof(head));
        ans+=dfs(s,INF);
    }
    printf("%d\n",ans);
    return 0;
}