# CCPC 2025 济南站 L. Activity Rehearsal 题解

[https://qoj.ac/contest/2693/problem/15043](https://qoj.ac/contest/2693/problem/15043)

## 题目大意

有 $n$（$2 \leq n \leq 10^5$）名同学排成一排，每人手里举着一个互不相同的数字牌 $a_i \in [1, n]$。

进行 $n-1$ 轮“比大小”活动，过程是：每轮取出队列最左边的两名同学进行比较：

1. **数字较大**的同学被淘汰出列（记录下他的数字）。
2. **数字较小**的同学回到队伍的最右边继续参与后续轮次。

给定 $m$（$1 \leq m \leq 10^5$）次操作，分为两种：

- `C x y`：交换初始位置在 $x$ 和 $y$ 上的同学手里的数字牌。
- `A l r`：查询第 $l$ 轮到第 $r$ 轮中，被淘汰出列的数字之和。

## 题目分析

**每一轮比较的同学位置是完全固定的，与他们手里的数字大小没有任何关系。**

我们可以把队列操作映射为给元素编号：

- 初始队伍的 $n$ 名同学编号为 $1,2,3,\dots,n$。

    | 轮数 | 淘汰 | 队列<u>（比较）</u> |
    | :---: | :---: | --- |
    | 1 | 4 | <u>4 3</u> 1 2 5 |
    | 2 | 2 | 4 3 <u>1 2</u> 5 3 |
    | 3 | 5 | 4 3 1 2 <u>5 3</u> 1 |
    | 4 | 3 | 4 3 1 2 5 3 <u>1 3</u> |
    | | | 4 3 1 2 5 3 1 3 1 |

- 以此类推，第 $k$ 轮：比较的永远是编号为 $2k-1$ 和 $2k$ 的元素，存活者获得新编号 $n+k$。

这构成了一棵固定结构的二叉树：

- 叶子节点：$1$ 到 $n$。
- 内部节点：$n+1$ 到 $2n-1$。节点 $n+k$ 代表第 $k$ 轮存活下来的元素，它的两个子节点分别是 $2k-1$ 和 $2k$。
- 第 $k$ 轮晋级的元素值 $\text{val}[n+k] = \min(\text{val}[2k-1],\text{val}[2k])$。
- 第 $k$ 轮淘汰的元素值 $\text{out}[k] = \max(\text{val}[2k-1],\text{val}[2k])$。

每次查询就是求 $\text{out}[l] + \text{out}[l+1] + \dots + \text{out}[r]$，可以使用线段树维护 $\text{out}$ 数组。

**如何实现交换操作？**

使用一个父节点数组 `fa`，对于每个节点 $i$，`fa[i]` 存储它的父节点编号，也就是这个位置的元素所影响的节点。交换操作后，向上更新父节点的值，直到遇到一个父节点的值没有改变为止。

- 以交换 $3$ 号同学和 $5$ 号同学为例：

    | 轮数 | 淘汰 | 队列<u>（比较）</u> |
    | :---: | :---: | --- |
    | 1 | 4 | <u>4 3</u> **5** 2 **1** |
    | 2 | 5 | 4 3 <u>**5** 2</u> **1** 3 |
    | 3 | 3 | 4 3 **5** 2 <u>**1** 3</u> **2** |
    | 4 | 2 | 4 3 **5** 2 **1** 3 <u>**2** **1**</u> |
    | | | 4 3 **5** 2 **1** 3 **2** **1** **1** |

- 每次比较的元素依旧是编号为 $2k-1$ 和 $2k$ 的元素。

交换后，如果淘汰的元素发生了改变，就更新对应的 $\text{out}$ 值以及线段树中的值，并继续向上更新父节点的值，直到遇到一个父节点的值没有改变为止。

## 完整代码

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;

int n, m;
int a[N];
int val[N << 1], out[N];
int fa[N << 1];
ll seg[N << 2];

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

void push_up(int p) {
    seg[p] = seg[ls] + seg[rs];
}

void build(int p, int l, int r) {
    if (l == r) {
        seg[p] = out[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    push_up(p);
}

void update(int p, int l, int r, int pos, int val) {
    if (l == r) {
        seg[p] = val;
        return;
    }
    if (pos <= mid) update(ls, l, mid, pos, val);
    else update(rs, mid + 1, r, pos, val);
    push_up(p);
}

ll query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return seg[p];
    }
    ll res = 0;
    if (ql <= mid) res += query(ls, l, mid, ql, qr);
    if (qr > mid) res += query(rs, mid + 1, r, ql, qr);
    return res;
}

//& 向上更新函数
void update_tournament(int pos, int new_val) {
    val[pos] = new_val;
    int cur = pos;

    while (fa[cur]) {
        int f = fa[cur];
        int k = f - n;

        int l = 2 * k - 1;
        int r = 2 * k;

        int n_min = min(val[l], val[r]);
        int n_max = max(val[l], val[r]);

        if (out[k] != n_max) {
            out[k] = n_max;
            update(1, 1, n - 1, k, n_max);
        }
        if (val[f] == n_min) {
            break;
        }
        
        val[f] = n_min;
        cur = f;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        val[i] = a[i];
    }

    //& 预处理模拟前 n-1 轮比较
    for (int k = 1; k < n; k++) {
        int l = 2 * k - 1;
        int r = 2 * k;

        fa[l] = k + n;
        fa[r] = k + n;

        val[k + n] = min(val[l], val[r]);
        out[k] = max(val[l], val[r]);
    }

    build(1, 1, n - 1);

    for (int i = 1; i <= m; i++) {
        char op;
        cin >> op;
        if (op == 'C') {
            int x, y;
            cin >> x >> y;
            int vx = val[x];
            int vy = val[y];
            update_tournament(x, vy);
            update_tournament(y, vx);
        }
        if (op == 'A') {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n - 1, l, r) << endl;
        }
    }

    return 0;
}
```

## 扩展

与这种二叉树类似的数据结构叫做锦标赛树（Tournament Tree），在处理淘汰赛场景时支持修改和查询操作。

锦标赛排序：[https://oi-wiki.org/basic/tournament-sort](https://oi-wiki.org/basic/tournament-sort)

## 反思

- 交换操作到底改变了什么？改变了沿途的胜负状态（数值）。
- 交换操作没有影响到什么？无法影响到整个队列两两元素的比较顺序（位置）。
