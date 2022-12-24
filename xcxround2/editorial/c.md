01 Trie 树

令 $d_i$ 为点 $i$ 到树根的权值异或和，则 $f(i, j) = d_i \oplus d_j$。

只需做一个 Trie 树，将 $d$ 数组所有值加入，然后对于每个 $d_i$，求 Trie 树中与其异或最大的值即可。

时间复杂度：$O(n \log_2 \max_{w_i})$
