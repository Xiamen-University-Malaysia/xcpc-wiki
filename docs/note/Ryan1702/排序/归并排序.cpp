#include<bits/stdc++.h>
#define Maxn 1000000
using namespace std;
int a[Maxn+5],mer[Maxn+5];
void merge_sort(int l,int r)
{
    if(l>=r) return ;
    int mid=(l+r)>>1;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r)
    {
        if(a[i]<a[j]) mer[k++]=a[i++];
        else mer[k++]=a[j++];
    }
    while(i<=mid) mer[k++]=a[i++];
    while(j<=r) mer[k++]=a[j++];
    for(int i=l;i<=r;i++) a[i]=mer[i];
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    merge_sort(0,n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}