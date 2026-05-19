#include<bits/stdc++.h>
#define Maxn 1000000
using namespace std;
int a[Maxn+5];
void down(int l,int r)
{
    int p=l,c=(l<<1)+1;
    while(c<=r)
    {
        if(c<r&&a[c]<a[c+1]) c++;
        if(a[p]>=a[c]) return ;
        else
        {
            swap(a[p],a[c]);
            p=c;
            c=(p<<1)+1;
        }
    }
}
void hpsort(int len)
{
    for(int i=(len-2)>>1;i>=0;i--) down(i,len-1);
    for(int i=len-1;i>0;i--)
    {
        swap(a[0],a[i]);
        down(0,i-1);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    hpsort(n);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}