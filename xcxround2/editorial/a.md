概率与期望 + `DP`

令 $f_i$ 为 $i$ 张卡的合成概率，显然
$$f_i = a\% \times f_{i-5} + \frac{1-a\%}{4} \times (f_{i-1} + f_{i-2} + f_{i-3} + f_{i-4})$$

初值：$f_5 = a\%$

答案：$f_b \times 100$

暴力转移即可，不需要额外算法。

时间复杂度：$O(b)$ per test case

空间复杂度：$O(b)$ per test case
