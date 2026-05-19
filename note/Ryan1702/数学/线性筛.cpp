#include<bits/stdc++.h>
#define Maxn 10000000
using namespace std;
bool flag[Maxn+5];
int ans[Maxn+5],tot;
void init(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!flag[i]) ans[++tot]=i;
        for(int j=1;j<=tot;j++)
        {
            if(i*ans[j]>n) break;
            flag[i*ans[j]]=true;
            if(i%ans[j]==0) break;
        }
    }
}
int main()
{
    init(100);
    for(int i=1;i<=tot;i++) printf("%d ",ans[i]);
    return 0;
}