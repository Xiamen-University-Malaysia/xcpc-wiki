#include<bits/stdc++.h>
#define Maxn 10000
#define Maxm 10000000
using namespace std;
typedef long long ll;
ll w[Maxn+5],v[Maxn+5],dp[Maxm+5];
int main()
{
    int n,W;
    scanf("%d%d",&W,&n);
    for(int i=0;i<n;i++) scanf("%lld%lld",w+i,v+i);
    for(int i=0;i<n;i++)
    {
        for(int j=w[i];j<=W;j++)
        {
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    printf("%lld\n",dp[W]);
    return 0;
}
