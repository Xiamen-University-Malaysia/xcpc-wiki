#include<bits/stdc++.h>
#define Maxn 1000000
using namespace std;
int a[Maxn+5],b[Maxn+5],c[Maxn+5];
void add(string sa,string sb,string &sc)
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    int n=0;
    for(int i=sa.length()-1;i>=0;i--) a[n++]=sa[i]-'0';
    int m=0;
    for(int i=sb.length()-1;i>=0;i--) b[m++]=sb[i]-'0';
    int len;
    if(n>m) len=n;
    else len=m;
    for(int i=0;i<len;i++)
    {
        c[i]+=a[i]+b[i];
        if(c[i]>9)
        {
            c[i]-=10;
            c[i+1]++;
        }
    }
    if(c[len]) len++;
    sc="";
    for(int i=len-1;i>=0;i--) sc+='0'+c[i];
    return ;
}
int main()
{
    string a,b,c;
    cin>>a>>b;
    add(a,b,c);
    cout<<c;
    return 0;
}
