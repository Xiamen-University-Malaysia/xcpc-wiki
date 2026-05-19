#include<bits/stdc++.h>
#define Maxn 100000
using namespace std;
int a[Maxn+5],d[Maxn+5],p[Maxn+5],pre[Maxn+5];
vector<int> ans;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    int k=0;
    for(int i=0;i<n;i++)
    {
        int tmp=upper_bound(d,d+k,a[i])-d; //最长不下降子序列
        // int tmp=lower_bound(d,d+k,a[i])-d; 最长上升子序列
        pre[i]=tmp?p[tmp-1]:-1;
        d[tmp]=a[i];
        p[tmp]=i;
        if(tmp==k) k++;
    }
    for(int i=p[k-1];i!=-1;i=pre[i]) ans.push_back(a[i]);
    printf("%d\n",ans.size());
    for(int i=ans.size()-1;i>=0;i--) printf("%d ",ans[i]);
    return 0;
}
