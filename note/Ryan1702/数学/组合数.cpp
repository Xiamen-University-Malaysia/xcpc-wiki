#include<bits/stdc++.h>
#define Maxn 1000
using namespace std;
int C[Maxn+5][Maxn+5];
void init(int n,int Mod)
{
    C[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
        {
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
        }
    }
}
int main()
{
    init(1000,1000000);
    return 0;
}