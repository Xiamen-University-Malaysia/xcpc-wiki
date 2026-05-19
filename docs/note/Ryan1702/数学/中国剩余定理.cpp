#include<bits/stdc++.h>
#define Maxn 10
using namespace std;
typedef long long ll;
ll yu[Maxn+5],m[Maxn+5],s[Maxn+5];
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    ll d=a;
    if(b==0)
    {
        x=1;
        y=0;
    }
    else
    {
        d=exgcd(b,a%b,x,y);
        x-=a/b*y;
        swap(x,y);
    }
    return d;
}
ll inv(ll a,ll b)
{
    ll x,y;
    ll d=exgcd(a,b,x,y);
    return (x%b+b)%b;
}
int main()
{
    int n;
    scanf("%d",&n);
    ll sum=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",m+i,yu+i);
        sum*=m[i];
    }
    for(int i=1;i<=n;i++) s[i]=inv(sum/m[i],m[i]);
    ll ans=0;
    for(int i=1;i<=n;i++) ans=(ans+(__int128)yu[i]*s[i]%sum*(sum/m[i]))%sum;
    printf("%lld\n",(ans%sum+sum)%sum);
    return 0;
}