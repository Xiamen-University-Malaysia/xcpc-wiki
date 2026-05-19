#include<bits/stdc++.h>
#define Maxn 10000
using namespace std;
typedef unsigned long long ull;
int n;
const int P=131;
ull p[Maxn+5],h[Maxn+5];
char s[Maxn+5];
void init()
{
    p[0]=1;
    h[0]=0;
    for(int i=1;i<=n;i++)
    {
        p[i]=p[i-1]*P;
        h[i]=h[i-1]*P+s[i];
    }
}
ull get(int l,int r)
{
    return h[r]-h[l-1]*p[r-l+1];
}
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    init();
    int l1,r1,l2,r2;
    while(scanf("%d%d%d%d",&l1,&r1,&l2,&r2)==4) printf(get(l1,r1)==get(l2,r2)?"Same\n":"Different\n");
}