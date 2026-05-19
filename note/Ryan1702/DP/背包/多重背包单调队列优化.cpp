#include<bits/stdc++.h>
#define Maxn 500
#define Maxm 1000
using namespace std;
int w[Maxn+5],v[Maxn+5],f[Maxm+5],dp[Maxm+5],cnt[Maxn+5];
int q[Maxm+5];
int main()
{
    int n,W;
    scanf("%d%d",&n,&W);
    for(int i=0;i<n;i++) scanf("%d%d%d",w+i,v+i,cnt+i);
    for(int i=0;i<n;i++)
    {
        memcpy(f,dp,sizeof(dp));
        for(int j=0;j<w[i];j++)
        {
            int h=0,t=-1;
            for(int k=j;k<=W;k+=w[i])
            {
                if(h<=t&&q[h]<k-cnt[i]*w[i]) h++;
                if(h<=t) dp[k]=max(f[k],f[q[h]]+(k-q[h])/w[i]*v[i]);
                while(h<=t&&f[k]>=f[q[t]]+(k-q[t])/w[i]*v[i]) t--;
                q[++t]=k;
            }
        }
    }
    printf("%d\n",dp[W]);
    return 0;
}