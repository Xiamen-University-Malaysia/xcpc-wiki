#include<bits/stdc++.h>
#define Maxn 500
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
ll w[Maxn+5][Maxn+5];
bool vb[Maxn+5];
ll la[Maxn+5],lb[Maxn+5];
ll d[Maxn+5];
int match[Maxn+5],pre[Maxn+5];
int n,m;
ll KM()
{
    for(int i=1;i<=n;i++) la[i]=-INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            la[i]=max(la[i],w[i][j]);
        }
    }
    for(int i=1;i<=n;i++) lb[i]=0;
    for(int u=1;u<=n;u++)
    {
        int x,y=0,id=0;
        ll del;
        for(int i=1;i<=n;i++) d[i]=INF;
        memset(vb,0,sizeof(vb));
        memset(pre,0,sizeof(pre));
        match[0]=u;
        while(match[y])
        {
            y=id;
            x=match[y];
            vb[y]=true;
            del=INF;
            for(int i=1;i<=n;i++)
            {
                if(!vb[i])
                {
                    if(la[x]+lb[i]-w[x][i]<d[i])
                    {
                        d[i]=la[x]+lb[i]-w[x][i];
                        pre[i]=y;
                    }
                    if(d[i]<del)
                    {
                        del=d[i];
                        id=i;
                    }
                }
            }
            for(int i=0;i<=n;i++)
            {
                if(vb[i])
                {
                    la[match[i]]-=del;
                    lb[i]+=del;
                }
                else d[i]-=del;
            }
        }
        for(;y;y=pre[y]) match[y]=match[pre[y]];
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=la[i]+lb[i];
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            w[i][j]=-INF;
        }
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;
        ll z;
        scanf("%d%d%lld",&x,&y,&z);
        w[x][y]=max(w[x][y],z);
    }
    printf("%lld\n",KM());
    for(int i=1;i<=n;i++) printf("%d ",match[i]);
    puts("");
    return 0;
}