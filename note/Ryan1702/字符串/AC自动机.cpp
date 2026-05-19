#include<bits/stdc++.h>
#define Maxn 1000000
using namespace std;
int ch[30][Maxn+5],nx[Maxn+5];
int cnt[Maxn+5],id;
char s[Maxn+5],t[Maxn+5];
void insert()
{
    int p=0;
    for(int i=0;s[i];i++)
    {
        if(!ch[s[i]-'a'][p]) ch[s[i]-'a'][p]=++id;
        p=ch[s[i]-'a'][p];
    }
    cnt[p]++;
}
void build()
{
    queue<int> q;
    for(int i=0;i<26;i++)
    {
        if(ch[i][0]) q.push(ch[i][0]);
    }
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<26;i++)
        {
            if(ch[i][x])
            {
                nx[ch[i][x]]=ch[i][nx[x]];
                q.push(ch[i][x]);
            }
            else ch[i][x]=ch[i][nx[x]];
        }
    }
}
int query()
{
    int p=0,ans=0;
    for(int i=0;t[i];i++)
    {
        p=ch[t[i]-'a'][p];
        // for(int j=p;j;j=nx[j]) ans+=cnt[j];
        for(int j=p;j&&~cnt[j];j=nx[j])
        {
            ans+=cnt[j];
            cnt[j]=-1;
        }
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        insert();
    }
    build();
    scanf("%s",t);
    printf("%d\n",query());
    return 0;
}