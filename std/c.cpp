#include <bits/stdc++.h>
#define int long long
using namespace std;
  
namespace trie {
    const int N = 100005 * 65;
    int cnt = 0;
    struct trieNode {
        int num, lc, rc;
        trieNode() {
            num = lc = rc = -1;
        }
    } trie[N]; // root = 0
    #define son(_x, _y) ((_y)? trie[_x].rc : trie[_x].lc)
    #define num(_x) trie[_x].num
    vector<int> div(int x) {
        vector<int> ret;
        for (int i = 1; i <= 60; i++) {
            ret.push_back(x & 1);
            x >>= 1;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    void insert(int x) {
        vector<int> bits = div(x);
        int p = 0;
        for (int i: bits) {
            if (son(p, i) == -1)
                son(p, i) = ++cnt;
            num(son(p, i)) = i;
            p = son(p, i);
        }
    }
    int calc(int x) {
        vector<int> bits = div(x);
        int p = 0, ans = 0;
        for (int i: bits) {
            if (son(p, i ^ 1) != -1) {
                ans = ans << 1 | 1;
                p = son(p, i ^ 1);
            } else {
                ans <<= 1;
                p = son(p, i);
            }
//          cout << ans << endl;
        }
        return ans;
    }
}
 
const int N = 100005;
int n, ans, a[N], d[N];
vector<int> g[N];
 
void dfs(int u, int fa) {
    d[u] ^= a[u];
    for (int v: g[u])
        if (v != fa)
            d[v] ^= d[u], dfs(v, u);
}
 
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); 
    }
    dfs(1, -1);
//  for (int i = 1; i <= n; i++)
//      cout << d[i] << " ";
//  cout << endl;
    for (int i = 1; i <= n; i++)
        trie::insert(d[i]);
    for (int i = 1; i <= n; i++)
        ans = max(ans, trie::calc(d[i]));
    cout << ans << endl;
    return 0;
}
