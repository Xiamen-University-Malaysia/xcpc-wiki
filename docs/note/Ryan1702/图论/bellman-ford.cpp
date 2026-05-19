#include<bits/stdc++.h>
#define Maxn 100000
#define Maxm 200000
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n,m,s;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],w[Maxm+5],tot;
int dis[Maxn+5];
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
bool bf(int s)
{
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    bool flag;
    int T=n;
    while(T--)
    {
        flag=false;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==INF) continue;
            for(int j=head[i];j!=-1;j=nex[j])
            {
                if(dis[i]+w[j]<dis[to[j]])
                {
                    dis[to[j]]=dis[i]+w[j];
                    flag=true;
                }
            }
        }
        if(!flag) break;
    }
    return flag;
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
    if(!bf(s))
    {
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==INF) dis[i]=(1ll<<31)-1;
            printf("%d ",dis[i]);
        }
    }
    else printf("Have at least one nagetive ring.");
    return 0;
}