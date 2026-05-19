#include<bits/stdc++.h>
#define Maxn 100
using namespace std;
int n,m;
int d[Maxn+5][Maxn+5],p[Maxn+5][Maxn+5];
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(d[i][k]+d[k][j]<d[i][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j]=k;
                }
            }
        }
    }
}
void path(int x,int y)
{
    if(!p[x][y]) return ;
    path(x,p[x][y]);
    printf("%d ",p[x][y]);
    path(p[x][y],y);
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=n;i++) d[i][i]=0;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        d[x][y]=min(d[x][y],z);
        d[y][x]=min(d[y][x],z);
    }
    floyd();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",d[i][j]);
        }
        puts("");
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",i);
            path(i,j);
            printf("%d\n",j);
        }
    }
    */
    return 0;
}