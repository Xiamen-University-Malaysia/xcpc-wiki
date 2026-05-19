#include<bits/stdc++.h>
#define Maxn 20000000
using namespace std;
typedef long long ll;
char s[Maxn+5],t[Maxn+5];
int z[Maxn+5],p[Maxn+5];
int main()
{
    scanf("%s%s",s+1,t+1);
    int n=strlen(s+1),m=strlen(t+1);
    z[1]=m;
    for(int i=2,l,r=0;i<=m;i++)
    {
        if(i<=r) z[i]=min(z[i-l+1],r-i+1);
        while(1+z[i]<=m&&i+z[i]<=m&&t[1+z[i]]==t[i+z[i]]) z[i]++;
        if(i+z[i]-1>r) l=i,r=i+z[i]-1;
    }
    for(int i=1,l,r=0;i<=n;i++)
    {
        if(i<=r) p[i]=min(z[i-l+1],r-i+1);
        while(1+p[i]<=m&&i+p[i]<=n&&t[1+p[i]]==s[i+p[i]]) p[i]++;
        if(i+p[i]-1>r) l=i,r=i+p[i]-1;
    }
    ll ans1=0,ans2=0;
    for(int i=1;i<=m;i++) ans1^=1ll*i*(z[i]+1);
    for(int i=1;i<=n;i++) ans2^=1ll*i*(p[i]+1);
    printf("%lld\n%lld\n",ans1,ans2);
    return 0;
}