#include<bits/stdc++.h>
#define Maxn 100000
#define Maxm 200000
using namespace std;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],tot,s,e,mx;
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
void dfs(int x,int fa,int len)
{
    if(len>mx)
    {
        mx=len;
        e=x;
    }
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(to[i]==fa) continue;
        dfs(to[i],x,len+1);
    }
    return ;
}
int main()
{
    int n;
    scanf("%d",&n);
    init();
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(1,-1,0);
    mx=0;
    s=e;
    dfs(s,-1,0);
    printf("%d\n",mx);
    return 0;
}