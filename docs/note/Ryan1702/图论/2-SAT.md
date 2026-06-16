# 2-SAT

``` c++
#include<bits/stdc++.h>
#define Maxn 2000000
#define Maxm 4000000
using namespace std;
int n,m;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],tot;
int dfn[Maxn+5],low[Maxn+5],t;
stack<int> st;
int in[Maxn+5];
int co[Maxn+5],col;
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
void tarjan(int x)
{
    dfn[x]=low[x]=++t;
    st.push(x);
    in[x]=true;
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(!dfn[to[i]])
        {
            tarjan(to[i]);
            low[x]=min(low[x],low[to[i]]);
        }
        else if(in[to[i]]) low[x]=min(low[x],dfn[to[i]]);
    }
    if(dfn[x]==low[x])
    {
        col++;
        while(st.top()!=x)
        {
            co[st.top()]=col;
            in[st.top()]=false;
            st.pop();
        }
        co[st.top()]=col;
        in[st.top()]=false;
        st.pop();
    }
}
int main()
{
    init();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        add(a+(!b)*n,c+d*n);
        add(c+(!d)*n,a+b*n);
    }
    for(int i=1;i<=2*n;i++)
    {
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(co[i]==co[i+n])
        {
            puts("IMPOSSIBLE");
            return 0;
        }
    }
    puts("POSSIBLE");
    for(int i=1;i<=n;i++)
    {
        printf("%d ",co[i]>co[i+n]);
    }
    puts("");
    return 0;
}
```