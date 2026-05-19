#include<bits/stdc++.h>
#define Maxn 1000
using namespace std;
int a[Maxn+5],n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=0;i<n;i++)
    {
        int p=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[p]) p=j;
        }
        swap(a[i],a[p]);
    }
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    puts("");
    return 0;
}
