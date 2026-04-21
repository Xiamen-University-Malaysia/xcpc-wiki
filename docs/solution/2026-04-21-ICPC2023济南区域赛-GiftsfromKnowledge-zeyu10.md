# ICPC 2023 济南区域赛 G 题解

[https://codeforces.com/gym/104901/problem/G](https://codeforces.com/gym/104901/problem/G)

## 题目大意

给定一个 $r \times c$ 的 $01$ 矩阵，可以选择反转一些行（第一列变成最后一列，以此类推），目标是每一列最多有一个 $1$。求方案数。

## 题目分析

由于反转操作是水平对称的，某一行 $i$ 中的元素 $b_{i, j}$ 在反转后只会移动到对称列 $c - 1 - j$（采用 0 索引）。这意味着：列 $j$ 和列 $c - 1 - j$ 是强绑定的，我们可以将它们作为一个“列对”来整体考虑。

对于任意一个列对 $(j, c - 1 - j)$，我们统计所有在这两列中包含 $1$ 的行：

1. **该行在这两列都是 $1$（使用 `vec2` 记录）：** 无论这行是否反转，都会在这两列各贡献一个 $1$。
   - 如果这样的行超过 1 个，必定会冲突，方案数为 $0$。
   - 如果这样的行恰好 1 个，那么这两列的容量被完全占满，任何其他行如果在这两列有 $1$，都会导致冲突，此时方案数也为 $0$。
2. **该行在这两列只有一个 $1$（使用 `vec1` 记录）：**
   - 如果这样的行超过 2 个，再怎么反转，至少有 3 个 $1$ 会落在容量仅为 2 的列对里，必然冲突，方案数为 $0$。
   - 如果这样的行恰好 2 个（记作行 $u$ 和行 $v$）：
     - 如果它们的 $1$ 初始时在**同侧**（都在列 $j$ 或都在列 $c - 1 - j$），为了错开它们，**两行必须做出不同的选择**（一个反转，一个不反转）。
     - 如果它们的 $1$ 初始时在**异侧**，为了避免撞到同一列，**两行必须做出相同的选择**（要么都不反转，要么都反转）。
   - 如果不存在这样的行或只有 1 个，不会产生任何约束。

奇数列数的特殊处理：如果 $c$ 是奇数，最中间的一列反转前后都在原位。我们只需要检查所有行在这个中间列上的 $1$ 的总数，如果超过 1 个则方案数为 $0$，否则不产生约束。

图论 / 并查集：上述分析提取出了行与行之间的限制关系（相同或相反）。是一个 2-SAT 问题：

- 对于每行 $i$，我们在并查集中分配两个节点：`i` 表示“不反转”，`i + r` 表示“反转”。
- 必须做出相同选择：`merge(u, v)` 且 `merge(u + r, v + r)`。
- 必须做出不同选择：`merge(u, v + r)` 且 `merge(u + r, v)`。

最后：

- 检查是否有某行要求 `i` 和 `i + r` 在同一个集合（自相矛盾），如果有，方案数为 $0$。
- 否则，并查集中独立连通块的数量为 $K$（因为对称性，$K$ 一定是偶数），答案即为 $2^{K/2} \pmod{10^9+7}$。

解释：在建图时，把每一行都拆分成了两个节点，导致最终找出的连通块数量是实际的两倍。

举例：

- 假设矩阵只有 $1$ 行，且没有任何冲突约束。
- 并查集中会有 $2$ 个节点：$1$（不反转）和 $2$（反转）。
- 因为没有约束，这 $2$ 个节点没有连线，所以各自独立，连通块数量 $K = 2$。
- 但这只代表 $1$ 个自由的行，它显然只有 $2$ 种选择（反转或不反转）。代入：$2^{K/2} = 2^{2/2} = 2^1 = 2$ 种方案。

## 完整代码

``` cpp
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;

string s[N];
int fa[2 * N];

int find(int x) {
    return (fa[x] == x) ? x : fa[x] = find(fa[x]);
}

void merge(int u, int v) {
    int fu = find(u);
    int fv = find(v);
    if (fu != fv) {
        fa[fu] = fv;
    }
}

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int r, c;
        cin >> r >> c;
        for (int i = 1; i <= r; i++) {
            cin >> s[i];
        }

        bool ans = true;
        for (int i = 1; i <= 2 * r; i++) {
            fa[i] = i;
        }
        for (int j = 0; j < c / 2; j++) {
            int _j = c - 1 - j;
            vector<int> vec1, vec2;
            
            for (int i = 1; i <= r; i++) {
                bool b1 = (s[i][j] == '1');
                bool b2 = (s[i][_j] == '1');
                if (b1 && b2) {
                    vec2.push_back(i);
                } else if (b1 || b2) {
                    vec1.push_back(i);
                }
            }

            if (vec2.size() > 1) {
                ans = false;
                break;
            }
            if (vec2.size() == 1 && !vec1.empty()) {
                ans = false;
                break;
            }
            
            if (vec2.empty()) {
                if (vec1.size() > 2) {
                    ans = false;
                    break;
                }
                if (vec1.size() == 2) {
                    int u = vec1[0];
                    int v = vec1[1];
                    bool su = (s[u][j] == '1');
                    bool sv = (s[v][j] == '1');
                    if (su == sv) {
                        merge(u, v + r);
                        merge(u + r, v);
                    } else {
                        merge(u, v);
                        merge(u + r, v + r);
                    }
                }
            }
        }

        if (ans && c % 2 != 0) {
            int j = c / 2;
            int cnt = 0;
            for (int i = 1; i <= r; i++) {
                if (s[i][j] == '1') {
                    cnt++;
                }
            }
            if (cnt > 1) {
                ans = false;
            }
        }

        if (!ans) {
            cout << 0 << "\n";
            continue;
        }

        for (int i = 1; i <= r; i++) {
            if (find(i) == find(i + r)) {
                ans = false;
                break;
            }
        }

        if (!ans) {
            cout << 0 << "\n";
            continue;
        }

        int cnt = 0;
        for (int i = 1; i <= 2 * r; i++) {
            if (fa[i] == i) {
                cnt++;
            }
        }

        cout << qpow(2, cnt / 2) << "\n";
    }

    return 0;
}
```
