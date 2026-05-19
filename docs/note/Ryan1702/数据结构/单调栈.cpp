#include<bits/stdc++.h>
#define Maxn 3000000
using namespace std;
int a[Maxn+5],st[Maxn+5],ans[Maxn+5];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	int top=0;
	for(int i=1;i<=n;i++)
	{
		while(top&&a[st[top]]<a[i]) ans[st[top--]]=i;
		st[++top]=i;
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
