#include<bits/stdc++.h>
#define Maxn 100000
using namespace std;
int ch[30][Maxn+5];
int cnt[Maxn+5],id;
void insert(char s[])
{
    int p=0;
    for(int i=0;s[i];i++)
    {
        if(!ch[s[i]-'a'][p]) ch[s[i]-'a'][p]=++id;
        p=ch[s[i]-'a'][p];
    }
    cnt[p]++;
}
int query(char s[])
{
    int p=0;
    for(int i=0;s[i];i++)
    {
        if(!ch[s[i]-'a'][p]) return 0;
        p=ch[s[i]-'a'][p];
    }
    return cnt[p];
}
int main()
{
    return 0;
}