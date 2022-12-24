#include <bits/stdc++.h>
using namespace std;

int n;
double p, t, f[10001];

int main() {
	cin >> p >> n;
	p /= 100;
	t = (1 - p) / 4;
	f[5] = p;
	for (int i = 6; i <= n; i++)
		f[i] = p + t * (f[i - 1] + f[i - 2] + f[i - 3] + f[i - 4]);
	cout << fixed << setprecision(15) << f[n] * 100 << "%" << endl;
	return 0;
}
