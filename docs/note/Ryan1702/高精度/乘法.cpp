#include<bits/stdc++.h>
#define Maxn 1000000
using namespace std;
int a[Maxn+5],b[Maxn+5],c[Maxn+5];
void mul(string sa,string sb,string &sc)
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    int n=0;
    for(int i=sa.length()-1;i>=0;i--) a[n++]=sa[i]-'0';
    int m=0;
    for(int i=sb.length()-1;i>=0;i--) b[m++]=sb[i]-'0';
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            c[i+j]+=a[i]*b[j];
            if(c[i+j]>9)
            {
                c[i+j+1]+=c[i+j]/10;
                c[i+j]%=10;
            }
        }
    }
    int len=n+m;
    while(!c[len-1]) len--;
    sc="";
    for(int i=len-1;i>=0;i--) sc+='0'+c[i];
}
int main()
{
    string a,b,c;
    cin>>a>>b;
    mul(a,b,c);
    cout<<c;
    return 0;
}
