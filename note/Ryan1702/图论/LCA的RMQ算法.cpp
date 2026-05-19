#include<bits/stdc++.h>
#define Maxn 1000000
using namespace std;
int n,m,root;
int head[Maxn+5],to[Maxn+5],nex[Maxn+5],tot;
int dfn[Maxn+5],dep[Maxn+5],cnt;
int st[25][Maxn+5],ans[25][Maxn+5],pos[Maxn+5],lg[Maxn+5];
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
void dfs(int x,int fa,int d)
{
    pos[x]=cnt;
    dep[cnt]=d;
    dfn[cnt++]=x;
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==fa) continue;
        dfs(to[i],x,d+1);
        dep[cnt]=d;
        dfn[cnt++]=x;
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&root);
    init();
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(root,-1,1);
    for(int i=2;i<=cnt;i++) lg[i]=lg[i>>1]+1;
    for(int i=0;i<cnt;i++)
    {
        st[0][i]=i;
        ans[0][i]=dfn[i];
    }
    for(int i=1;i<=lg[cnt];i++)
    {
        for(int j=0;j<cnt+1-(1<<i);j++)
        {
            if(dep[st[i-1][j]]<dep[st[i-1][j+(1<<(i-1))]])
            {
                st[i][j]=st[i-1][j];
                ans[i][j]=ans[i-1][j];
            }
            else
            {
                st[i][j]=st[i-1][j+(1<<(i-1))];
                ans[i][j]=ans[i-1][j+(1<<(i-1))];
            }
        }
    }
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x=pos[x];
        y=pos[y];
        if(x>y) swap(x,y);
        int len=y-x+1;
        len=lg[len];
        printf("%d\n",(dep[st[len][x]]<dep[st[len][y-(1<<len)+1]])?ans[len][x]:ans[len][y-(1<<len)+1]);
    }
    return 0;
}