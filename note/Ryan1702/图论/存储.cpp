#include<bits/stdc++.h>
#define Maxn 1000
#define Maxm 5000
using namespace std;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],w[Maxm+5],tot;
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
int main()
{
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    return 0;
}