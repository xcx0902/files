# Overall Editorial Of XCX Round #2

## Problem A

概率与期望 + `DP`

令 $f_i$ 为 $i$ 张卡的合成概率，显然
$$f_i = a\% \times f_{i-5} + \frac{1-a\\%}{4} \times (f_{i-1} + f_{i-2} + f_{i-3} + f_{i-4})$$

初值：$f_5 = a\%$

答案：$f_b \times 100$

暴力转移即可，不需要额外算法。

时间复杂度：$O(b)$ per test case

空间复杂度：$O(b)$ per test case

## Problem B

高精度 + 二分

二分每一位的值，并使用高精度乘法判断即可。

令 $T = 120$，即保留的位数。

时间复杂度：$O(\log_2 x + T \times \log_2 10 \times T^2)$ per test case

空间复杂度：$O(T)$ per test case

## Problem C

01 Trie 树

令 $d_i$ 为点 $i$ 到树根的权值异或和，则 $f(i, j) = d_i \oplus d_j$。

只需做一个 Trie 树，将 $d$ 数组所有值加入，然后对于每个 $d_i$，求 Trie 树中与其异或最大的值即可。

时间复杂度：$O(n \log_2 \max_{w_i})$

## Problem D

模拟

由于是大模拟，不再赘述。细节详见代码。

## Problem E

分块

本题原题为 [LOJ 6285 数列分块入门 9](https://loj.ac/p/6285)。
