#include<bits/stdc++.h>
#define Maxn 100000
using namespace std;
struct node
{
	int s[2];
	int p,v,cnt,size;
	void init(int p1,int v1)
	{
		p=p1;
		v=v1;
		cnt=size=1;
	}
}tr[Maxn+5];
int root,id;
void pushup(int x)
{
	tr[x].size=tr[tr[x].s[0]].size+tr[tr[x].s[1]].size+tr[x].cnt;
}
void rotate(int x)
{
	int y=tr[x].p,z=tr[y].p;
	int k=tr[y].s[1]==x;
	tr[y].s[k]=tr[x].s[k^1];
	tr[tr[x].s[k^1]].p=y;
	tr[x].s[k^1]=y;
	tr[y].p=x;
	tr[z].s[tr[z].s[1]==y]=x;
	tr[x].p=z;
	pushup(y);
	pushup(x);
}
void splay(int x,int k)
{
	while(tr[x].p!=k)
	{
		int y=tr[x].p,z=tr[y].p;
		if(z!=k) (tr[y].s[0]==x)^(tr[z].s[0]==y)?rotate(x):rotate(y);
		rotate(x);
	}
	if(k==0) root=x;
}
void find(int v)
{
	int x=root;
	while(tr[x].s[v>tr[x].v]&&v!=tr[x].v)
	{
		x=tr[x].s[v>tr[x].v];
	}
	splay(x,0);
}
int get_pre(int v)
{
	find(v);
	int x=root;
	if(tr[x].v<v) return x;
	x=tr[x].s[0];
	while(tr[x].s[1]) x=tr[x].s[1];
	splay(x,0);
	return x;
}
int get_suc(int v)
{
	find(v);
	int x=root;
	if(tr[x].v>v) return x;
	x=tr[x].s[1];
	while(tr[x].s[0]) x=tr[x].s[0];
	splay(x,0);
	return x;
}
void dlt(int v)
{
	int pre=get_pre(v),suc=get_suc(v);
	splay(pre,0);
	splay(suc,pre);
	int del=tr[suc].s[0];
	if(tr[del].cnt>1)
	{
		tr[del].cnt--;
		splay(del,0);
	}
	else
	{
		tr[suc].s[0]=0;
		splay(suc,0);
	}
}
void insert(int v)
{
	int x=root,p=0;
	while(x&&tr[x].v!=v)
	{
		p=x;
		x=tr[x].s[v>tr[x].v];
	}
	if(x) tr[x].cnt++;
	else
	{
		x=++id;
		tr[p].s[v>tr[p].v]=x;
		tr[x].init(p,v);
	}
	splay(x,0);
}
int get_rank(int v)
{
	insert(v);
	int res=tr[tr[root].s[0]].size;
	dlt(v);
	return res;
}
int get_val(int k)
{
	int x=root;
	while(1)
	{
		int y=tr[x].s[0];
		if(tr[y].size+tr[x].cnt<k)
		{
			k-=tr[y].size+tr[x].cnt;
			x=tr[x].s[1];
		}
		else
		{
			if(tr[y].size>=k) x=y;
			else break;
		}
	}
	splay(x,0);
	return tr[x].v;
}
int main()
{
	int n;
	scanf("%d",&n);
	insert(-1e9);
	insert(1e9);
	for(int i=1;i<=n;i++)
	{
		int op,x;
		scanf("%d%d",&op,&x);
		if(op==1) insert(x);
		else if(op==2) dlt(x);
		else if(op==3) printf("%d\n",get_rank(x));
		else if(op==4) printf("%d\n",get_val(x+1));
		else if(op==5) printf("%d\n",tr[get_pre(x)].v);
		else printf("%d\n",tr[get_suc(x)].v);
	}
	return 0;
}
