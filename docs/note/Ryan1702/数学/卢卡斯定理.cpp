#include<bits/stdc++.h>
#define Maxn 10000
#define Mod 13331
using namespace std;
int fac[Maxn+5];
int exgcd(int a,int b,int &x,int &y)
{
    int d=a;
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
int inv(int b,int M)
{
    int x,y;
    int d=exgcd(b,M,x,y);
    return (x%M+M)%M;
}
int C(int x,int y)
{
    if(x<y) return 0;
    return 1ll*fac[x]*inv(fac[x-y],Mod)%Mod*inv(fac[y],Mod)%Mod;
}
int lucas(int x,int y)
{
    if(y==0) return 1;
    return 1ll*lucas(x/Mod,y/Mod)*C(x%Mod,y%Mod)%Mod;
}
int main()
{
    fac[0]=1;
    for(int i=1;i<=Maxn;i++) fac[i]=fac[i-1]*i;
}