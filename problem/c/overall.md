# 2077's Skill Tree

## 题目背景

![](https://cdn.luogu.com.cn/upload/image_hosting/65n4aas8.png)

$2077$ 年，`Skill Tree` 变成了一棵树。热爱 `Florr` 的小 X 对其展开了深入研究。

## 题目描述

`Skill Tree` 里，每个技能都有一个花费，且以树的形式展现（如背景里的图片）。这棵树共有 $n$ 个点。`M28` 说，定义 $f(i, j)$ 为 $i$ 点到 $j$ 点的最短路径中经过的点的花费的异或和。他还说，如果有人可以求出对于 `Skill Tree`，$\max_{i=1}^{n}\max_{j=i+1}^{n}f(i,j)$ 的值，就给他一个 ![](https://cdn.luogu.com.cn/upload/image_hosting/rhczkt1c.png)。

小 X 很喜欢 ![](https://cdn.luogu.com.cn/upload/image_hosting/rhczkt1c.png)，可他并不会算，所以就来请你帮忙。对于第一个算出来的人，小 X 的朋友小 M 会给他 1RMB。

## 输入格式

第一行，一个整数 $n$。

第二行，$n$ 个整数，表示每个节点的花费 $w_i$。

第三至 $n+1$ 行，每行两个整数 $u, v$，表示 $u$ 和 $v$ 连边。

## 输出格式

一行，表示答案。

## 样例 #1

### 样例输入 #1

```
5
1 2 3 4 5
1 2
1 3
2 4
2 5
```

### 样例输出 #1

```
7
```

## 提示

对于 $20\%$ 的数据，$1 \le n \le 100$。

对于 $40\%$ 的数据，$1 \le n \le 1000$。

对于 $100\%$ 的数据，$1 \le n \le 100000, 0 \le w_i < 2^{64}$。