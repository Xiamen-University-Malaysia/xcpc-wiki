#include<bits/stdc++.h>
#define Maxn 1000
#define Maxm 5000
using namespace std;
int n;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],tot;
int c[Maxn+5];
vector<int> t;
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
bool dfs(int x)
{
    c[x]=-1;
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(c[to[i]]<0) return false;
        else if(!c[to[i]])
        {
            if(!dfs(to[i])) return false;
        }
    }
    c[x]=1;
    t.push_back(x);
    return true;
}
bool tp()
{
    t.clear();
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++)
    {
        if(!c[i])
        {
            if(!dfs(i)) return false;
        }
    }
    reverse(t.begin(),t.end());
    return true;
}
int main()
{
    init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        while(scanf("%d",&x)==1&&x)
        {
            add(i,x);
        }
    }
    if(tp())
    {
        for(int i=0;i<t.size();i++) printf("%d ",t[i]);
    }
    return 0;
}