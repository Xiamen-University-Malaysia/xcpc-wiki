#include<bits/stdc++.h>
#define Maxn 500
#define Maxm 50000
using namespace std;
int n,m,e;
int head[Maxn+5],to[Maxm+5],nex[Maxm+5],tot;
bool vis[Maxn+5];
int match[Maxn+5];
void init()
{
	memset(head,-1,sizeof(head));
	tot=0;
}
void add(int x,int y)
{
	to[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
}
bool dfs(int x)
{
	for(int i=head[x];i!=-1;i=nex[i])
	{
		if(vis[to[i]]) continue;
		vis[to[i]]=true;
		if(!match[to[i]]||dfs(match[to[i]]))
		{
			match[to[i]]=x;
			return 1;
		}
	}
	return 0;
}
int main()
{
	init();
	scanf("%d%d%d",&n,&m,&e);
	for(int i=1;i<=e;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i)) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
