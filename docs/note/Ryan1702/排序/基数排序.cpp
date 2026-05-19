#include<bits/stdc++.h>
#define Maxn 1000000
using namespace std;
int a[Maxn+5],n;
vector<int> ans[2][15];
int pw(int x)
{
    int ans=1;
    while(x--) ans*=10;
    return ans;
}
void numsort(int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<10;j++) ans[(i&1)^1][j].clear();
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<ans[i&1][j].size();k++)
            {
                int tmp=ans[i&1][j][k];
                ans[(i&1)^1][a[tmp]/pw(i)%10].push_back(tmp);
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    int mx=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        int tmp=a[i],cnt=0;
        while(tmp)
        {
            tmp/=10;
            cnt++;
        }
        mx=max(mx,cnt);
        ans[0][0].push_back(i);
    }
    numsort(mx);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<ans[mx&1][i].size();j++)
        {
            printf("%d ",a[ans[mx&1][i][j]]);
        }
    }
    return 0;
}