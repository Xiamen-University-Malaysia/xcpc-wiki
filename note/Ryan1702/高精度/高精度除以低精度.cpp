#include<bits/stdc++.h>
#define Maxn 1000000
using namespace std;
typedef long long ll;
int a[Maxn+5],c[Maxn+5];
void div(string sa,int ib,string &sc)
{
    if(!ib)
    {
        sc="Error!";
        return ;
    }
    memset(a,0,sizeof(a));
    memset(c,0,sizeof(c));
    int n=0;
    for(int i=0;i<sa.length();i++) a[n++]=sa[i]-'0';
    ll t=0;
    for(int i=0;i<n;i++)
    {
        t=t*10+a[i];
        if(t>=ib)
        {
            c[i]=t/ib;
            t%=ib;
        }
        else c[i]=0;
    }
    int s=0;
    while(s<n-1&&!c[s]) s++;
    sc="";
    for(int i=s;i<n;i++) sc+='0'+c[i];
    sc+="......";
    memset(c,0,sizeof(c));
    n=0;
    while(t)
    {
        c[n++]=t%10;
        t/=10;
    }
    for(int i=n-1;i>=0;i--) sc+='0'+c[i];
    return ;
}
int main()
{
    string a,c;
    int b;
    cin>>a>>b;
    div(a,b,c);
    cout<<c;
    return 0;
}
