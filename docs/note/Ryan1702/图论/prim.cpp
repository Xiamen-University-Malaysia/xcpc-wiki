#include<bits/stdc++.h>
#define Maxn 5000
#define Maxm 200000
using namespace std;
int n,m;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],w[Maxm+5],tot;
int d[Maxn+5];
bool vis[Maxn+5];
priority_queue<pair<int,int> > q;
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
int prim(int s)
{
    while(!q.empty()) q.pop();
    q.push(make_pair(0,s));
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    d[s]=0;
    int ans=0,cnt=0;
    while(!q.empty())
    {
        int x=q.top().second;
        q.pop();
        if(vis[x]) continue;
        vis[x]=true;
        ans+=d[x];
        cnt++;
        for(int i=head[x];i!=-1;i=nex[i])
        {
            if(w[i]<d[to[i]])
            {
                d[to[i]]=w[i];
                q.push(make_pair(-d[to[i]],to[i]));
            }
        }
    }
    if(cnt==n) return ans;
    else return -1;
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
    int ans=prim(1);
    if(ans==-1) printf("orz\n");
    else printf("%d\n",ans);
    return 0;
}