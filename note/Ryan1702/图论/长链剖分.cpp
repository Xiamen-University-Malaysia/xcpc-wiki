#include<bits/stdc++.h>
#define Maxn 1000000
#define Maxm 2000000
using namespace std;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],tot;
int len[Maxn+5],son[Maxn+5];
int buf[2*Maxn+5],*dp[Maxn+5],*p;
int ans[Maxn+5];
void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
}
void add(int x,int y)
{
    to[++tot]=y;
    nex[tot]=head[x];
    head[x]=tot;
}
void dfs1(int x,int f)
{
    len[x]=1;
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==f) continue;
        dfs1(to[i],x);
        if(len[to[i]]>len[son[x]]) son[x]=to[i];
    }
    len[x]=len[son[x]]+1;
}
void dfs2(int x,int f)
{
    dp[x][0]=1;
    if(son[x])
    {
        dp[son[x]]=dp[x]+1;
        dfs2(son[x],x);
        ans[x]=ans[son[x]]+1;
    }
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==f||to[i]==son[x]) continue;
        dp[to[i]]=p;
        p+=len[to[i]];
        dfs2(to[i],x);
        for(int j=0;j<len[to[i]];j++)
        {
            dp[x][j+1]+=dp[to[i]][j];
            if(dp[x][j+1]>dp[x][ans[x]]||(dp[x][j+1]==dp[x][ans[x]]&&j+1<ans[x])) ans[x]=j+1;
        }
    }
    if(dp[x][ans[x]]==1) ans[x]=0;
}
int main()
{
    init();
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs1(1,0);
    p=buf;
    dp[1]=p;
    p+=len[1];
    dfs2(1,0);
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}