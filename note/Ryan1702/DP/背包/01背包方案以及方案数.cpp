#include<bits/stdc++.h>
#define Maxn 1000
#define Maxm 40000
using namespace std;
int w[Maxn+5],v[Maxn+5],dp[Maxm+5],dp_num[Maxm+5];
bool path[Maxn+5][Maxm+5];
stack<int> st;
int main()
{
    int n,W;
    scanf("%d%d",&W,&n);
    for(int i=0;i<n;i++) scanf("%d%d",w+i,v+i);
    dp_num[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=W;j>=w[i];j--)
        {
            if(dp[j]<dp[j-w[i]]+v[i])
            {
                dp[j]=dp[j-w[i]]+v[i];
                path[i][j]=1; //记录前i个物品中使得总价值最大时是否有选择第i个物品
            }
            dp_num[j]+=dp_num[j-w[i]]; //求刚好凑成j重量的选择方案数
        }
    }
    printf("%d\n",W);
    for(int i=0;i<=W;i++) printf("%d ",dp_num[i]);
    puts("");
    printf("%d\n",dp[W]);
    int sum=W;
    for(int i=n-1;i>=0;i--)
    {
        if(path[i][sum])
        {
            st.push(i);
            sum-=w[i];
        }
    }
    while(!st.empty())
    {
        printf("%d ",st.top()+1);
        st.pop();
    }
    return 0;
}
