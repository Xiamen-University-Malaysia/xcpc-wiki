#include<bits/stdc++.h>
#define Maxn 1000
#define Maxm 10000000
using namespace std;
int w[Maxn+5],v[Maxn+5],dp[Maxm+5],cnt[Maxm+5];
int main()
{
    int n,W;
    scanf("%d%d",&W,&n);
    for(int i=0;i<n;i++) scanf("%d%d",w+i,v+i);
    cnt[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=W;j>=w[i];j--)
        {
            int ans=max(dp[j],dp[j-w[i]]+v[i]);
            int c=0;
            if(ans==dp[j]) c+=cnt[j];
            if(ans==dp[j-w[i]]+v[i]) c+=cnt[j-w[i]];
            dp[j]=ans;
            cnt[j]=c; //前i个物品中容量为j总价值为dp[j]的方案数
        }
    }
    printf("%d %d\n",dp[W],cnt[W]);
    return 0;
}
