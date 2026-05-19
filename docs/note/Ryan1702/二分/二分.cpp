// 找最小的n，使得n阶乘末尾有k个0
#include<bits/stdc++.h>
#define Maxn 1000
using namespace std;
int get(int x)
{
    int ans=0;
    while(x)
    {
        ans+=x/5;
        x/=5;
    }
    return ans;
}
int main()
{
    int k;
    scanf("%d",&k);
    int l=1,r=10000000,best=-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(get(mid)>=k)
        {
            best=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    printf("%d",best);
    return 0;
}
