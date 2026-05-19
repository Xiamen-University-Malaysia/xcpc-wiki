#include<bits/stdc++.h>
using namespace std;
int fun1(int n)
{
    int ans=0;
    for(int L=1,R;L<=n;L=R+1)
    {
        R=n/(n/L);
        ans+=(R-L+1)*(n/L);
    }
    return ans;
}
int fun2(int n)
{
    int ans=0;
    for(int i=1;i<=n;i++) ans+=n/i;
    return ans;
}
int main()
{
    int n=50;
    while(n--) printf("%d %d\n",fun1(n),fun2(n));
    return 0;
}