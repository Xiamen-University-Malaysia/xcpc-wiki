#include<bits/stdc++.h>
#define Maxn 100
#define eps 1e-6
using namespace std;
int n;
double a[Maxn+5][Maxn+5];
int gaosi()
{
	for(int i=1;i<=n;i++)
	{
		int r=i;
		for(int j=i;j<=n;j++)
		{
			if(fabs(a[j][i])>eps)
			{
				r=j;
				break;
			}
		}
		swap(a[r],a[i]);
		if(fabs(a[i][i])<eps) return 0;
		for(int j=n+1;j>=i;j--) a[i][j]/=a[i][i];
		for(int j=i+1;j<=n;j++)
		{
			for(int k=n+1;k>=i;k--)
			{
				a[j][k]-=a[j][i]*a[i][k];
			}
		}
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			a[i][n+1]-=a[i][j]*a[j][n+1];
		}
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			scanf("%lf",&a[i][j]);
		}
	}
	if(gaosi())
	{
		for(int i=1;i<=n;i++) printf("%.2f\n",a[i][n+1]);
	}
	else printf("No Solution\n");
	return 0;
}
