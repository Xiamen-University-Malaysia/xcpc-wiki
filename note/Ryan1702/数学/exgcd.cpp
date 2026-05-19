#include<bits/stdc++.h>
#define Maxn 10000
using namespace std;
int exgcd(int a,int b,int &x,int &y)
{
    int d=a;
    if(b==0)
    {
        x=1;
        y=0;
    }
    else
    {
        d=exgcd(b,a%b,x,y);
        x-=a/b*y;
        swap(x,y);
    }
    return d;
}
int main()
{
    int a,b,c,x,y;
    while(scanf("%d%d%d",&a,&b,&c)==3)
    {
        int g=exgcd(a,b,x,y);
        if(c%g) printf("No answer.\n");
        else
        {
            bool f=false;
            int dx=b/g,dy=a/g;
            for(int d=-Maxn;d<=Maxn;d++)
            {
                int ansx=c/g*x+d*dx;
                int ansy=c/g*y-d*dy;
                if(ansx<0) continue;
                if(ansy<0) continue;
                printf("x=%d,y=%d\n",ansx,ansy);
                f=true;
            }
            if(!f) printf("No positive answer.\n");
        }
        puts("");
    }
    return 0;
}