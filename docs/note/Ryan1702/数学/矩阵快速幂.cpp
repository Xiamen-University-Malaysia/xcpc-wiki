#include<bits/stdc++.h>
#define Maxn 100
#define Mod 1000000007
using namespace std;
typedef long long ll;
struct matrix
{
	ll a[Maxn+5][Maxn+5];
	matrix()
	{
		memset(a,0,sizeof(a));
	}
};
int n;
ll k;
matrix operator*(matrix &A,matrix &B)
{
	matrix C;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j]%Mod)%Mod;
			}
		}
	}
	return C;
}
matrix operator^(matrix &A,ll &num)
{
	matrix C;
	for(int i=1;i<=n;i++) C.a[i][i]=1;
	while(num)
	{
		if(num&1) C=C*A;
		A=A*A;
		num>>=1;
	}
	return C;
}
int main()
{
	matrix A,B;
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&A.a[i][j]);
		}
	}
	B=A^k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%lld ",B.a[i][j]);
		}
		puts("");
	}
	return 0;
}
