#include<bits/stdc++.h>
#define Maxn 80
using namespace std;
typedef __int128 ll;
ll a[Maxn+5][Maxn+5],dp[Maxn+5][Maxn+5];
ll read()
{
    ll x=0;
    char c=' ';
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x;
}
void print(ll x)
{
    if(x>10) print(x/10);
    putchar('0'+x%10);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            a[i][j]=read();
        }
    }
    ll ans=0;
    for(int r=0;r<n;r++)
    {
        for(int i=0;i<m;i++) dp[i][i]=a[r][i]<<1;
        for(int len=2;len<=m;len++)
        {
            for(int i=0;i<m;i++)
            {
                int j=i+len-1;
                dp[i][j]=max((a[r][i]<<1)+(dp[i+1][j]<<1),(a[r][j]<<1)+(dp[i][j-1]<<1));
            }
        }
        ans+=dp[0][m-1];
    }
    print(ans);
}