#include<bits/stdc++.h>
#define Maxn 1000
#define Maxm 1000000
using namespace std;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],tot;
int co[Maxn+5];
void init()
{
	memset(head,-1,sizeof(head));
	memset(co,0,sizeof(co));
	tot=0;
}
void add(int x,int y)
{
	to[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
}
bool dfs(int x,int c)
{
	co[x]=c;
	for(int i=head[x];i!=-1;i=nex[i])
	{
		if(!co[to[i]])
		{
			if(!dfs(to[i],3-c)) return 0;
		}
		else if(co[to[i]]==c) return 0;
	}
	return 1;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		init();
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		printf("case %d:\n",t);
		bool flag=false;
		for(int i=1;i<=n;i++)
		{
			if(!co[i])
			{
				if(!dfs(i,1))
				{
					flag=true;
					break;
				}
			}
		}
		if(flag) printf("No\n");
		else printf("Yes\n");
	}
}
