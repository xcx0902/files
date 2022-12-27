# Crafting

## 题目背景

小 M 热爱 [`Florr`](https://florr.io)。

`Florr` 中有“许多”种合成方法（~~其实只有6种~~）。

[小视频，可能会对你有所帮助](https://www.bilibili.com/video/BV1Q8411b74e/?spm_id_from=333.337.search-card.all.click)

[这个才是真的](https://www.bilibili.com/video/BV1PP4y127nC/?spm_id_from=333.337.search-card.all.click)

[$\color{white}{这个才是真正真的}$](https://www.bilibili.com/video/BV1qD4y1t741/?spm_id_from=333.337.search-card.all.click)

[$\color{white}{\text{This is really truly video.}}$](http://gxoi.ddwoo.top/file/mythic_crafting.gif)

## 题目描述

一天，小 M 想要合成很多卡，但他怕烧卡太多导致没卡用。于是，他想知道合成概率。

合成方法：$5$ 个一合成，有 $a\%$ 的概率成功，成功会变成一个更高等级的卡，失败会随机扣除 $1 \sim 4$ 个（这里假设扣除 $1 \sim 4$ 个的概率均等）。

## 输入格式

$t$ 组数据。

每组数据，一行两个数，$a, b$， 保证 $a, b$ 为整数。

## 输出格式

每行一个精确到 $5$ 位的数，为合成至少一个的概率。(为百分数形式）。

## 样例 #1

### 样例输入 #1

```
10
4 7035
13 3629
17 6411
63 5598
95 758
1 78
2 100
29 41
6 48
5 46
```

### 样例输出 #1

```
100.00000%
100.00000%
100.00000%
100.00000%
100.00000%
26.00759%
54.26415%
99.35181%
66.94335%
58.42885%
```

## 提示

$1 \le a \le 100$

$1 \le b \le 10^{5}$