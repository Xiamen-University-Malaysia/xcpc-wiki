# 企鹅

[https://www.luogu.com.cn/problem/P14452](https://www.luogu.com.cn/problem/P14452)

## 题目描述

有 $n$ 只企鹅站在数轴上。第 $i$ 只企鹅最初位于坐标 $a_i$ 处。保证所有的 $a_i$ 互不相同。

每只企鹅都会选择一个目标企鹅，记为 $t_i$（$1 \leq t_i \leq n$，且 $t_i \neq i$）。在时间 $0$ 时，所有企鹅同时开始移动。每只企鹅以每秒 $0.5$ 个单位长度的速度，朝着其目标企鹅当前所在的位置移动。

当第 $i$ 只企鹅与它的目标企鹅 $t_i$ 相遇时（即二者在同一时刻到达同一坐标），它会立即停止移动。对于每只企鹅，请你求出它停止移动的时间。

可以证明，每只企鹅都会在有限的时间内停止，且停止时间总是一个整数。

## 输入格式

输入的第一行包含一个整数 $n$（$2 \leq n \leq 5 \cdot 10^5$），表示企鹅的数量。

第二行包含 $n$ 个整数 $t_1, t_2, \ldots, t_n$（$1 \leq t_i \leq n$，且 $t_i \neq i$），其中 $t_i$ 表示第 $i$ 只企鹅选择的目标企鹅编号。

第三行包含 $n$ 个互不相同的整数 $a_1, a_2, \ldots, a_n$（$-5 \cdot 10^8 \leq a_i \leq 5 \cdot 10^8$），其中 $a_i$ 表示第 $i$ 只企鹅的初始坐标。

## 输出格式

输出一行，包含 $n$ 个整数，其中第 $i$ 个整数表示第 $i$ 只企鹅停止移动的时间（单位为秒）。

## 输入输出样例 #1

### 输入 #1

```
3
2 3 1
-1 2 3
```

### 输出 #1

```
7 1 4
```

## 输入输出样例 #2

### 输入 #2

```
10
8 3 6 7 1 8 2 10 8 1
0 -14 5 -3 14 -12 11 8 -18 17
```

### 输出 #2

```
25 21 17 14 14 49 29 9 61 17
```

## 说明/提示

在第一个样例中：

最初，第 2 只企鹅位于第 1 只企鹅的右侧，因此第 1 只企鹅向右移动。同样地，第 2 只企鹅也向右移动，而第 3 只企鹅向左移动。

在第 $1$ 秒时，第 2 只企鹅与第 3 只企鹅在 $x = 2.5$ 处相遇，此时第 2 只企鹅停止移动。

此时，第 1 只企鹅的位置是 $x = -0.5$，第 2 只企鹅的位置是 $x = 2.5$，二者之间的距离为 $3$。由于第 1 只企鹅以每秒 $0.5$ 个单位的速度移动，它还需要 $6$ 秒才能到达第 2 只企鹅。因此，第 1 只企鹅在第 $7$ 秒时停止。

在第 1 只企鹅停止之前，第 3 只企鹅会在第 $4$ 秒与它相遇。因此，答案分别为 $7$、$1$ 和 $4$。

# 题解

## 建立模型

$n$个点$n$条边，每个点只有一条出边，表示起点的目标是终点。

我们不难发现当一个点的答案只由自己目标节点决定

所以可以考虑$DP$

但是$n$个点$n$条边

意味着每个连通块内都有且仅有一个环

所以考虑断掉环上的一条边$i$使得该连通块变为一棵树

这棵树是以$i$的终点$root$为根节点

现在这个问题拆分成了两个子问题：

1. $root$的答案怎么算？
2. 树上$DP$如何递推？



首先先来解决问题一

为了保证root答案的正确性

需要在环上选择最早停止的企鹅

因为最早停止的企鹅停止时双方一定满足

- 相向而行
    - 反证法
    - 因为如果最早停止的是同向而行的企鹅
    - 在前面的企鹅必然要先停下才能被后面的企鹅追上
    - 前面的企鹅先停下与假设矛盾
- 双方在上一个时刻都在行动
    - 反证法
    - 因为如果有一方已经停止
    - 与假设最早停止矛盾

在环上所有$u\rightarrow v$，且$u$和$v$相向而行中寻找两个距离最接近的即$abs(a_u-a_v)$最小

假设距离最小的一对是$u_0\rightarrow v_0$

$root=u_0$

$ans_{root}=abs(a_{u_0}-a_{v_0})$

至此算出了$root$的答案



接着来解决问题二

针对任一对$u\rightarrow v$

假设当前得知$v$的答案

考虑是否可以推出$u$的答案

分两种情况

1. $u$和$v$同向而行
2. $u$和$v$相向而行

$$
dist=u和v之间的距离=abs(a_u-a_v)\\
Situation~1:ans_u=2\times dist+ans_v\\
Situation~2:ans_u=max(dist,2\times dist-ans_v)
$$

## 代码实现

``` c++
#include<bits/stdc++.h>
#define Maxn 500000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
ll a[Maxn+5];
int t[Maxn+5],dir[Maxn+5];
int head[Maxn+5],to[Maxn+5],nex[Maxn+5],tot;
ll mn;
int root,edge;
bool vis[Maxn+5],flag;
ll ans[Maxn+5];
void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
}
void add(int x,int y)
{
    to[++tot]=y;
    nex[tot]=head[x];
    head[x]=tot;
}
void dfs2(int x,int ed)
{
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(i==ed) continue;
        ans[to[i]]=(dir[x]==dir[to[i]])?
          ans[x]+2*abs(a[x]-a[to[i]]):
      		max(abs(a[x]-a[to[i]]),2*abs(a[x]-a[to[i]])-ans[x]);
        dfs2(to[i],ed);
    }
}
void dfs1(int x,int start)
{
    vis[x]=true;
    for(int i=head[x];i!=-1;i=nex[i])
    {
        if(vis[to[i]]&&to[i]!=start) continue;
        if(to[i]==start)
        {
            flag=true;
            if(dir[x]!=dir[to[i]])
            {
                if(abs(a[x]-a[to[i]])<mn)
                {
                    mn=abs(a[x]-a[to[i]]);
                    edge=i;
                    root=to[i];
                }
            }
            return ;
        }
        dfs1(to[i],start);
        if(flag)
        {
            if(dir[x]!=dir[to[i]])
            {
                if(abs(a[x]-a[to[i]])<mn)
                {
                    mn=abs(a[x]-a[to[i]]);
                    edge=i;
                    root=to[i];
                }
            }
            return ;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    init();
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        add(x,i);
        t[i]=x;
    }
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    for(int i=1;i<=n;i++) dir[i]=a[t[i]]>a[i]?1:-1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            mn=INF;
            flag=false;
            dfs1(i,i);
            if(mn!=INF)
            {
                ans[root]=mn;
                dfs2(root,edge);
            }
        }
    }
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
    puts("");
    return 0;
}
```