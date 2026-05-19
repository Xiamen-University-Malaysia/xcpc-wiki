#include<bits/stdc++.h>
#define Maxn 10000000
using namespace std;
bool flag[Maxn+5];
int ans[Maxn+5],tot;
int phi[Maxn+5];
void init(int n)
{
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!flag[i])
        {
            ans[++tot]=i;
            phi[i]=i-1;
        }
        for(int j=1;j<=tot;j++)
        {
            if(i*ans[j]>n) break;
            flag[i*ans[j]]=true;
            if(i%ans[j]==0)
            {
                phi[i*ans[j]]=phi[i]*ans[j];
                break;
            }
            phi[i*ans[j]]=phi[i]*(ans[j]-1);
        }
    }
}
int main()
{
    init(100);
    for(int i=1;i<=100;i++) printf("%d ",phi[i]);
    return 0;
}