#include<bits/stdc++.h>
#define Maxn 100
#define Maxm 40000
using namespace std;
int w[Maxn+5],v[Maxn+5],dp[Maxm+5],cnt[Maxn+5];
int main()
{
    int n,W;
    scanf("%d%d",&n,&W);
    for(int i=0;i<n;i++) scanf("%d%d%d",v+i,w+i,cnt+i);
    for(int i=0;i<n;i++)
    {
        int k=cnt[i];
        for(int tmp=1;tmp<k;tmp<<=1)
        {
            for(int j=W;j>=tmp*w[i];j--)
            {
                dp[j]=max(dp[j],dp[j-tmp*w[i]]+tmp*v[i]);
            }
            k-=tmp;
        }
        for(int j=W;j>=k*w[i];j--)
        {
            dp[j]=max(dp[j],dp[j-k*w[i]]+k*v[i]);
        }
    }
    printf("%d\n",dp[W]);
    return 0;
}
