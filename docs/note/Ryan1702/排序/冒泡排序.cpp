#include<bits/stdc++.h>
#define Maxn 1000
using namespace std;
int a[Maxn+5],n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    bool flag=true;
    while(flag)
    {
        flag=false;
        for(int i=1;i<n;i++)
        {
            if(a[i]<a[i-1])
            {
                swap(a[i],a[i-1]);
                flag=true;
            }
        }
    }
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    puts("");
    return 0;
}
