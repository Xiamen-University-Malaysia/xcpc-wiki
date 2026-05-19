#include<bits/stdc++.h>
#define Maxn 10000
using namespace std;
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
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)==2) printf("%d\n",inv(a,b));
    return 0;
}