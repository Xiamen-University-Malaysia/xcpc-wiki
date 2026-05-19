#include<bits/stdc++.h>
#define Maxn 1000
using namespace std;
int f[Maxn+5];
void init(int n)
{
    f[1]=0;
    f[2]=1;
    for(int i=3;i<=n;i++) f[i]=(i-1)*(f[i-1]+f[i-2]);
}
int main()
{
    init(100);
    return 0;
}