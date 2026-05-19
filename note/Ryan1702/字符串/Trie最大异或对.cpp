#include<bits/stdc++.h>
#define Maxn 100000
using namespace std;
int a[Maxn+5];
int ch[35][Maxn*35+5];
int cnt[Maxn*35+5],id;
void insert(int x)
{
    int p=0;
    for(int i=30;i>=0;i--)
    {
        int j=(x>>i)&1;
        if(!ch[j][p]) ch[j][p]=++id;
        p=ch[j][p];
    }
    cnt[p]++;
}
int query(int x)
{
    int p=0,ans=0;
    for(int i=30;i>=0;i--)
    {
        int j=(x>>i)&1;
        if(ch[!j][p])
        {
            p=ch[!j][p];
            ans+=1<<i;
        }
        else p=ch[j][p];
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        insert(a[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,query(a[i]));
    printf("%d\n",ans);
    return 0;
}