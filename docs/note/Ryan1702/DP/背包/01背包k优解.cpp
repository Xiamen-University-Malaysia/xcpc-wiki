#include<bits/stdc++.h>
#define Maxn 100
#define Maxm 1000
#define Maxk 30
using namespace std;
int w[Maxn+5],v[Maxn+5],dp[Maxm+5][Maxk+5],a[Maxk+5],b[Maxk+5];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,W,K;
        scanf("%d%d%d",&n,&W,&K);
        for(int i=0;i<n;i++) scanf("%d",v+i);
        for(int i=0;i<n;i++) scanf("%d",w+i);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=W;j>=w[i];j--)
            {
                for(int k=1;k<=K;k++)
                {
                    a[k]=dp[j][k];
                    b[k]=dp[j-w[i]][k]+v[i];
                }
                a[K+1]=-1;
                b[K+1]=-1;
                int p=1,q=1,r=1;
                while(r<=K&&(a[p]!=-1||b[q]!=-1))
                {
                    if(a[p]>b[q]) dp[j][r]=a[p++];
                    else dp[j][r]=b[q++];
                    if(dp[j][r]!=dp[j][r-1]) r++;
                }
            }
        }
        printf("%d\n",dp[W][K]);
    }
    return 0;
}
