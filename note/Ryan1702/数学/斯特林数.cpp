#include<bits/stdc++.h>
#define Maxn 1000
using namespace std;
int dp[Maxn+5][Maxn+5];
void init(int n,int Mod)
{
    //第一类斯特林数:n个不同小球放入k个环里的方案数
    dp[0][0]=dp[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=((i-1)*dp[i-1][j]+dp[i-1][j-1])%Mod;
        }
    }
    //第二类斯特林数:n个不同的小球放入k个非空集合的方案数
    dp[0][0]=dp[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=(j*dp[i-1][j]+dp[i-1][j-1])%Mod;
        }
    }
}
int main()
{
    init(1000,1000000);
    return 0;
}