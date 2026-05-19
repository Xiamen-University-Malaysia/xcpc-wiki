#include<bits/stdc++.h>
#define Maxn 1000000
using namespace std;
char s[Maxn+5],t[Maxn+5];
int nx[Maxn+5];
int main()
{
    scanf("%s%s",s+1,t+1);
    int n=strlen(s+1),m=strlen(t+1);
    nx[1]=0;
    for(int i=2,j=0;i<=m;i++)
    {
        while(j&&t[j+1]!=t[i]) j=nx[j];
        if(t[j+1]==t[i]) j++;
        nx[i]=j;
    }
    for(int i=1,j=0;i<=n;i++)
    {
        while(j&&t[j+1]!=s[i]) j=nx[j];
        if(t[j+1]==s[i]) j++;
        if(j==m) printf("%d\n",i-m+1);
    }
    for(int i=1;i<=m;i++) printf("%d ",nx[i]);
    return 0;
}