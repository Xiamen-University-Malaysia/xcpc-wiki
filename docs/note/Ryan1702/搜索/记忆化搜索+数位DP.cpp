#include<bits/stdc++.h>
#define Maxn 20
using namespace std;
int dp[15][Maxn+5],a[Maxn+5];
int dfs(int pos,int num)
{
    if(pos==0) return num==4?0:1;
    if(dp[num][pos]!=-1) return dp[num][pos];
    int res=0;
    for(int i=0;i<10;i++) res+=dfs(pos-1,i);
    if(num==6) res-=dfs(pos-1,2);
    if(num==4) return dp[num][pos]=0;
    return dp[num][pos]=res;
}
int calc(int x)
{
    int cnt=0;
    while(x)
    {
        a[cnt++]=x%10;
        x/=10;
    }
    int ans=1;
    bool flag=false;
    for(int i=cnt-1;i>=0;i--)
    {
        for(int j=0;j<a[i];j++) ans+=dfs(i,j);
        if(flag&&a[i]>2) ans-=dfs(i,2);
        if(flag&&a[i]==2)
        {
            ans-=1;
            break;
        }
        if(a[i]==4)
        {
            ans-=1;
            break;
        }
        if(a[i]==6) flag=true;
        else flag=false;
    }
    return ans;
}
int check(int x)
{
    int ans=x+1;
    vector<int> v;
    for(int i=0;i<=x;i++)
    {
        v.clear();
        int tmp=i;
        while(tmp)
        {
            v.push_back(tmp%10);
            tmp/=10;
        }
        for(int j=v.size()-1;j>=0;j--)
        {
            if(v[j]==4)
            {
                ans-=1;
                break;
            }
            if(j>0&&v[j]==6&&v[j-1]==2)
            {
                ans-=1;
                break;
            }
        }
    }
    return ans;
}
int main()
{
    int c=0;
    for(int T=5001;T<=10000;T++)
    {
        memset(dp,-1,sizeof(dp));
        if(calc(T)!=check(T))
        {
            cout<<T<<endl;
            c++;
        }
    }
    cout<<"Error: "<<c<<endl;
    return 0;
}