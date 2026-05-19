#include<bits/stdc++.h>
using namespace std;
int quickpow(int x,int y,int m)
{
	int res=1;
	while(y)
	{
		if(y&1) res=1ll*res*x%m;
		x=1ll*x*x%m;
		y>>=1;
	}
	return res;
}
int main()
{
	int x,y,m;
	scanf("%d%d%d",&x,&y,&m);
	printf("%d^%d mod %d=%d\n",x,y,m,quickpow(x,y,m));
}
