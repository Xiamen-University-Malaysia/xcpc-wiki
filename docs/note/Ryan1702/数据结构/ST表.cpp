#include<bits/stdc++.h>
#define Maxn 100000
using namespace std;
int f[25][Maxn+5],lg[Maxn+5];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++) scanf("%d",&f[0][i]);
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=n-(1<<i)+1;j++)
		{
			f[i][j]=max(f[i-1][j],f[i-1][j+(1<<(i-1))]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int j=lg[y-x+1];
		printf("%d\n",max(f[j][x],f[j][y-(1<<j)+1]));
	}
}
