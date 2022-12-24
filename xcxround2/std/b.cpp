#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int N = 1001;
int l, r, ans, mid, tmp1, tmp2, flag;
int t, n, nlen, a[N], b[N], c[N], d[N];
 
int isok(int len) {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    tmp2 = (len - 1) << 1;
    for (int i = len - 1, j = 0; i >= 0; i--)
        a[j++] = c[i];
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
            b[i + j] += a[i] * a[j];
    len = (len << 1) - 1;
    for (int i = 0; i < len; i++)
        b[i + 1] += b[i] / 10, b[i] %= 10;
    while (b[len])
        b[len + 1] += b[len] / 10, b[len++] %= 10;
    if (len - tmp2 < nlen) return -1;
    if (len - tmp2 > nlen) return 1;
    tmp2 = len - 1;
    for (int i = len - 1, j = nlen - 1; i >= 0 && j >= 0; i--, j--) {
        if (d[j] > b[i]) return -1;
        if (d[j] < b[i]) return 1;
        tmp2 = i - 1;
    }
    while (tmp2 >= 0)
        if (b[tmp2--])
            return 1;
    return 0;
}
 
signed main() {
    scanf("%lld", &t);
    while (t--) {
        memset(c, 0, sizeof c);
        flag = nlen = 0;
        scanf("%lld", &n);
        tmp1 = n;
        while (tmp1) {
            d[nlen++] = tmp1 % 10;
            tmp1 /= 10;
        }
//      cerr << "inited" << endl;
        l = 1, r = n;
        while (l <= r) {
            mid = (l + r) >> 1;
            c[0] = mid;
            tmp1 = isok(1);
            if (tmp1 > 0) r = mid - 1;
            else if (tmp1 < 0) ans = mid, l = mid + 1;
            else if (tmp1 == 0) {
                ans = mid, flag = 1;
                break;
            }
        }
        c[0] = ans;
//      cerr << "calced c[0]" << endl;
        for (int i = 1; i <= 120; i++) {
            if (flag) continue;
            l = 0, r = 9;
            while (l <= r) {
                mid = (l + r) / 2;
                c[i] = mid;
                tmp1 = isok(i + 1);
                if (tmp1 > 0) r = mid - 1;
                else if (tmp1 < 0) ans = mid, l = mid + 1;
                else if (tmp1 == 0) {
                    ans = mid, flag = 1;
                    break;
                }
            }
            c[i] = ans;
//          cerr << "calced c[" << i << "]" << endl;
        }
        tmp1 = -1;
        for (int i = 120; i >= 1; i--)
            if (c[i]) {
                tmp1 = i;
                break;
            }
        printf("%lld%s", c[0], (tmp1 != -1? "." : ""));
        for (int i = 1; i <= tmp1; i++)
            printf("%lld", c[i]);
        printf("\n");
    }
    return 0;
}
