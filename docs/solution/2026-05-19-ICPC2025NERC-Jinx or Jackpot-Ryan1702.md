# 老虎机

[https://codeforces.com/contest/2181/problem/J](https://codeforces.com/contest/2181/problem/J)

## 题意

$A$有$1000$美元，去赌场玩老虎机，老虎机的中奖概率是由一个序列决定的

在制作这个老虎机时，随机从概率序列中选择一个$a_i$，并让这个老虎机中奖的概率为$a_i\%$

注意：老虎机只会有一个固定的中奖概率，且$A$不知道，$A$只知道这个序列

一共有$k$次游玩机会，每次游玩可以选择投入$X$，且不能贷款，$X$可以等于$0$

这个老虎机只会有两种结果

- 中奖，收回$2X$
- 未中奖，收回$0$

给定$n,k$以及

一个长度为$n$的序列，表示$n$个概率，分别为$a_1,a_2,a_3,...,a_n$，每个数表示的是中奖概率为$a_i\%$

$k$表示$A$最多可以玩的局数

## 思路

考虑一段固定长度为$a+b$的前缀序列，包含$a$次中奖、$b$次未中奖，对应概率为$p^a(1-p)^b$

因此可以等效看作存在一个自动机，按如下概率生成下一个结果为头奖：

$$p(a,b) = \frac{\sum p^{a+1}(1-p)^b}{\sum p^a(1-p)^b}$$

其中$a$为当前已中奖次数，$b$为当前未中奖次数

接下来定义状态$dp(a,b,x)$：表示当前已中奖$a$次、未中奖$b$次、持有资金$x$时，能获得的最大期望收益

状态转移方程为：

当$a+b < k$时：

$$dp(a,b,x)=\max_{\substack{0\leq y\leq x}}\big(p(a,b)\cdot dp(a+1,b,x+y)+(1-p(a,b))\cdot dp(a,b+1,x-y)\big)$$

当$a+b = k$时：

$$dp(a,b,x) = x$$

易得最优策略仅为全额下注或不下注

于是可设$dp(a,b,x)=C[a][b]\cdot x$，递推公式改写为：

当$a+b < k$时：

$$C[a][b] = \max\big(p(a,b)C[a+1][b]+(1-p(a,b))C[a][b+1],\ 2p(a,b)C[a+1][b]\big)$$

当$a+b = k$时：

$$C[a][b]=1$$

## 代码

``` c++
#include<bits/stdc++.h>
#define Maxn 30
#define Maxm 1000000
using namespace std;
int n,k;
double a[Maxm+5];
double dp[Maxn+5][Maxn+5],f[Maxn+5][Maxn+5];
double qp(double x,int y)
{
    double ans=1;
    while(y)
    {
        if(y&1) ans*=x;
        y>>=1;
        x*=x;
    }
    return ans;
}
double p(int x,int y)
{
    if(f[x][y]) return f[x][y];
    double sum1=0,sum2=0;
    for(int i=1;i<=n;i++)
    {
        sum1+=qp(a[i]/100,x+1)*qp(1-a[i]/100,y);
        sum2+=qp(a[i]/100,x)*qp(1-a[i]/100,y);
    }
    if(sum2==0.0)
    {
        if(sum1==0.0) return f[x][y]=0;
        return f[x][y]=1;
    }
    return f[x][y]=sum1/sum2;
}
double dfs(int x,int y)
{
    if(dp[x][y]) return dp[x][y];
    if(x+y>=k) return dp[x][y]=1;
    return dp[x][y]=max(p(x,y)*dfs(x+1,y)+(1-p(x,y))*dfs(x,y+1),2*p(x,y)*dfs(x+1,y));
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lf",a+i);
    printf("%.5f\n",1000*(dfs(0,0)-1));
    return 0;
}
```