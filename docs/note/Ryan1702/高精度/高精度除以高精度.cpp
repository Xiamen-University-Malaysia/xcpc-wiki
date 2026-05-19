#include<bits/stdc++.h>
#define Maxn 10000
using namespace std;
int a[Maxn+5],b[Maxn+5],c[Maxn+5],d[Maxn+5];
void sub(string sa,string sb,string &sc)
{
    if(sa==sb)
    {
        sc="0";
        return ;
    }
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
        c[i]+=a[i]-b[i];
        if(c[i]<0)
        {
            c[i]+=10;
            c[i+1]--;
        }
    }
    while(!c[len-1]&&len>1) len--;
    sc="";
    for(int i=len-1;i>=0;i--) sc+='0'+c[i];
}
void div(string sa,string sb,string &sc)
{
    if(sb=="0")
    {
        sc="Error!";
        return ;
    }
    memset(d,0,sizeof(d));
    string tt="";
    for(int i=0;i<sa.length();i++)
    {
        if(tt=="0") tt="";
        tt+=sa[i];
        while(tt.length()>sb.length()||(tt.length()==sb.length()&&tt>=sb))
        {
            string ans;
            sub(tt,sb,ans);
            tt=ans;
            d[i]++;
        }
    }
    int s=0;
    while(s<sa.length()-1&&!d[s]) s++;
    sc="";
    for(int i=s;i<sa.length();i++) sc+='0'+d[i];
    if(tt!=""&&tt!="0") sc+="......"+tt;
    return ;
}
int main()
{
    string a,b,c;
    cin>>a>>b;
    div(a,b,c);
    cout<<c;
    return 0;
}
