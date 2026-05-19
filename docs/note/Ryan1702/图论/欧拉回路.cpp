#include<bits/stdc++.h>
#define Maxn 1024
using namespace std;
vector<pair<int,int> > g[Maxn+5];
stack<int> st;
int d[Maxn+5],cnt[Maxn+5];
void dfs(int x)
{
    for(int i=0;i<g[x].size();i++)
    {
        int v=g[x][i].first,id=g[x][i].second;
        if(!cnt[id]) continue;
        cnt[id]--;
        dfs(v);
    }
    st.push(x);
}
int main()
{
    int n=0,s=Maxn,m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(make_pair(y,i));
        g[y].push_back(make_pair(x,i));
        s=min(s,min(x,y));
        n=max(n,max(x,y));
        d[x]++;
        d[y]++;
        cnt[i]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]%2)
        {
            s=i;
            break;
        }
    }
    for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
    dfs(s);
    while(!st.empty())
    {
        printf("%d\n",st.top());
        st.pop();
    }
    return 0;
}
