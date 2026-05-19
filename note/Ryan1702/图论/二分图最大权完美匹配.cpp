#include<bits/stdc++.h>
#define Maxn 500
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
ll w[Maxn+5][Maxn+5];
bool va[Maxn+5],vb[Maxn+5];
ll la[Maxn+5],lb[Maxn+5],d[Maxn+5];
int match[Maxn+5];
int n,m;
bool dfs(int x)
{
    va[x]=true;
    for(int i=1;i<=n;i++)
    {
        if(vb[i]) continue;
        if(la[x]+lb[i]==w[x][i])
        {
            vb[i]=true;
            if(!match[i]||dfs(match[i]))
            {
                match[i]=x;
                return true;
            }
        }
        else d[i]=min(d[i],la[x]+lb[i]-w[x][i]);
    }
    return false;
}
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
    for(int i=1;i<=n;i++)
    {
        while(true)
        {
            memset(va,0,sizeof(va));
            memset(vb,0,sizeof(vb));
            memset(d,0x3f,sizeof(d));
            if(dfs(i)) break;
            ll tmp=INF;
            for(int j=1;j<=n;j++)
            {
                if(!vb[j]) tmp=min(tmp,d[j]);
            }
            for(int j=1;j<=n;j++)
            {
                if(va[j]) la[j]-=tmp;
                if(vb[j]) lb[j]+=tmp;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=la[match[i]]+lb[i];
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