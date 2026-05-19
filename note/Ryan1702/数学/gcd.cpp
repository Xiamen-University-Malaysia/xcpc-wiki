#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
    while(x&&y)
    {
        if(x<y) y%=x;
        else x%=y;
    }
    return max(x,y);
}
int main()
{
    int x,y;
    while(scanf("%d%d",&x,&y)==2) printf("%d\n",gcd(x,y));
    return 0;
}