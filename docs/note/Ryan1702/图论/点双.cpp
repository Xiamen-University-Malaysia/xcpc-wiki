#include<bits/stdc++.h>
#define Maxn 500000
#define Maxm 4000000
using namespace std;
int n,m,root;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],tot;
int dfn[Maxn+5],low[Maxn+5],t;
bool cut[Maxn+5];
stack<int> st;
vector<int> dcc[Maxn+5];
int cnt;
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
    if(x==root&&head[x]==-1)
    {
        dcc[++cnt].push_back(x);
        return ;
    }
    dfn[x]=low[x]=++t;
    st.push(x);
    int child=0;
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(!dfn[to[i]])
        {
            tarjan(to[i]);
            low[x]=min(low[x],low[to[i]]);
            if(low[to[i]]>=dfn[x])
            {
                child++;
                if(x!=root||child>1) cut[x]=true;
                int y;
                cnt++;
                do
                {
                    y=st.top();
                    st.pop();
                    dcc[cnt].push_back(y);
                }while(y!=to[i]);
                dcc[cnt].push_back(x);
            }
        }
        else low[x]=min(low[x],dfn[to[i]]);
    }
}
int main()
{
    init();
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==y) continue;
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
        {
            root=i;
            tarjan(i);
        }
    }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++)
    {
        printf("%d ",dcc[i].size());
        for(int j=0;j<dcc[i].size();j++) printf("%d ",dcc[i][j]);
        puts("");
    }
    /*
    int num=cnt;
    for(int i=1;i<=n;i++)
    {
        if(cut[i]) id[i]=++num;
    }
    init();
    for(int i=1;i<=cnt;i++)
    {
        for(int j=0;j<dcc[i].size();j++)
        {
            if(cut[dcc[i][j]])
            {
                add(id[i],i);
                add(i,id[i]);
            }
        }
    }
    */
    return 0;
}