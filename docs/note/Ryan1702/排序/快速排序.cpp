#include<bits/stdc++.h>
#define Maxn 1000000
using namespace std;
int a[Maxn+5];
void qs(int L,int R)
{
    int l=L,r=R;
    if(l>=r) return ;
    int tmp=a[l];
    while(l<r)
    {
        while(l<r&&tmp<=a[r]) r--;
        a[l]=a[r];
        while(l<r&&tmp>=a[l]) l++;
        a[r]=a[l];
    }
    a[l]=tmp;
    qs(L,l-1);
    qs(l+1,R);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    qs(0,n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}