#include<bits/stdc++.h>
#define Maxn 5000
using namespace std;
vector<pair<int,pair<int,int> > > v;
int fa[Maxn+5];
int Find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=Find(fa[x]);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        v.push_back(make_pair(z,make_pair(x,y)));
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++) fa[i]=i;
    int ans=0,cnt=0;
    for(int i=0;i<m;i++)
    {
        int x=Find(v[i].second.first);
        int y=Find(v[i].second.second);
        if(x!=y)
        {
            fa[x]=y;
            ans+=v[i].first;
            cnt++;
        }
    }
    if(cnt==n-1) printf("%d\n",ans);
    else printf("orz\n");
    return 0;
}