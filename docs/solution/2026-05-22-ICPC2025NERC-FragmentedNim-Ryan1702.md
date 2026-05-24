# 取石子

[https://codeforces.com/contest/2181/problem/F](https://codeforces.com/contest/2181/problem/F)

## 题意

有$n$堆石头，第$i$堆有$a_i$个石头。

Alice和Bob轮流执行以下操作

- 对手帮自己指定一堆非空石头
- 自己从被指定的石头堆中取任意个石头

已知Alice先手，且双方绝顶聪明，取光所有石头的一方获胜

$T$组数据，判断谁会获胜

输入

```
3
3
1 2 3
1
1
5
10 3 4 7 4
```

输出

```
Bob
Alice
Alice
```

样例一

- Bob选择第一堆，Alice从中拿了一个
- Alice选择第三堆，Bob从中拿了两个
- Bob选择第三堆，Alice从中拿了一个
- Alice选择第二堆，Bob从中拿了两个，获胜

## 思路

对方给自己指定了一堆个数大于1的石子，则自己必赢

为什么？

分类讨论：两种情况

1. 如果当前状况除去这堆石子的状态是先手必赢

    那么自己就可以取到只剩一个石子

    然后指定对手去取这堆

    那么对手就必须只能取这个

    那么先手必赢的局面就是自己得到

2. 如果当前状况除去这堆石子的状态是先手必输

    那么自己就可以把这堆所有都取完

    然后就把先手必输的局面交给对手

    所以自己就是必赢局面

所以双方思路都是就是

尽可能选择一堆个数等于1的给对方

就是只要看1的个数

注意：还要特殊考虑一下全都是1的情况

## 代码

``` c++
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,cnt=0,add=0;
        scanf("%d",&n);
        while(n--)
        {
            int x;
            scanf("%d",&x);
            if(x==1) cnt++;
            else add=1;
        }
        printf((cnt+add)%2?"Alice\n":"Bob\n");
    }
    return 0;
}
```