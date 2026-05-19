#include<bits/stdc++.h>
#define Maxn 1000
#define Maxm 10000000
using namespace std;
int w[Maxn+5],v[Maxn+5],dp[Maxm+5];
int main()
{
    int n,W;
    scanf("%d%d",&W,&n);
    for(int i=0;i<n;i++) scanf("%d%d",w+i,v+i);
    for(int i=0;i<n;i++)
    {
        for(int j=W;j>=w[i];j--)
        {
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    printf("%d\n",dp[W]);
    return 0;
}
