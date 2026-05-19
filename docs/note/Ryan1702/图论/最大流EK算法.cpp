#include<bits/stdc++.h>
#define Maxn 200
#define Maxm 10000
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],tot;
ll w[Maxm+5];
int pre[Maxn+5];
ll mf[Maxn+5];
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
bool bfs(int s,int t)
{
    memset(mf,0,sizeof(mf));
    queue<int> q;
    q.push(s);
    mf[s]=INF;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=head[x];i!=-1;i=nex[i])
        {
            if(mf[to[i]]==0&&w[i])
            {
                mf[to[i]]=min(mf[x],w[i]);
                pre[to[i]]=i;
                q.push(to[i]);
                if(to[i]==t) return true;
            }
        }
    }
    return false;
}
ll cal(int s,int t)
{
    ll ans=0;
    while(bfs(s,t))
    {
        int v=t;
        while(v!=s)
        {
            int i=pre[v];
            w[i]-=mf[t];
            w[i^1]+=mf[t];
            v=to[i^1];
        }
        ans+=mf[t];
    }
    return ans;
}
int main()
{
    init();
    int n,m,s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        ll z;
        scanf("%d%d%lld",&x,&y,&z);
        add(x,y,z);
        add(y,x,0);
    }
    printf("%lld\n",cal(s,t));
    return 0;
}
