#include<bits/stdc++.h>
#define Maxn 110000000
using namespace std;
char s[2*Maxn+5],t[Maxn+5];
int d[Maxn+5];
int main()
{
    scanf("%s",t+1);
    int cnt=strlen(t+1);
    int n=0;
    s[++n]='.';
    s[++n]='#';
    for(int i=1;i<=cnt;i++)
    {
        s[++n]=t[i];
        s[++n]='#';
    }
    d[1]=1;
    for(int i=2,l,r=1;i<=n;i++)
    {
        if(i<=r) d[i]=min(d[r-i+l],r-i+1);
        while(s[i-d[i]]==s[i+d[i]]) d[i]++;
        if(i+d[i]-1>r) l=i-d[i]+1,r=i+d[i]-1;
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,d[i]-1);
    printf("%d\n",ans);
    return 0;
}