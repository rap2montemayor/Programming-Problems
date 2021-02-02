#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fastpow(ll n, ll x) {
	if (n == 1 or x == 0) return 1;
	if (x == 1) return n;
	ll res = 1;
	while (x > 0) {
		if (x % 2 == 1) res = (res*n);
		x /= 2;
		n *= n;
	}
	return res;
}

int main() {
	int m, n;
	cin >> m >> n;

	ll ans = 0;
	for (int i = 1; i <= m; ++i)
		ans += i * (fastpow(i, n) - fastpow(i-1, n));

	cout << ans << ' ' << fastpow(m, n) << '\n';

	return 0;
}