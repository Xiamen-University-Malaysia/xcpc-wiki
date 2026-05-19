#include<bits/stdc++.h>
#define Maxn 1000
using namespace std;
int a[Maxn+5],n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=1;i<n;i++)
    {
        int val=a[i],j=i-1;
        while(j>=0&&a[j]>val)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=val;
    }
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    puts("");
    return 0;
}
