#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll m = (1e9 + 7);
vector<ll> fac(1e7, 1);
vector<bool> isgood(1e7, true);

ll modpow(ll n, ll x) {
	if (n == 1 or x == 0) return 1;
	if (x == 1) return n;

	ll res = 1;
	n %= m;
	while (x > 0) {
		if (x % 2 == 1) res = (res*n) % m;
		x /= 2;
		n = (n*n) % m;
	}
	return res % m;
}

ll inverse(ll n) {
	return modpow(n, m - 2);
}

ll comb(ll n, ll r) {
	if (n == r or n == 0) return 1;
	ll num = fac[n];
	ll denom = (fac[r] * fac[n-r]) % m;
	return (num * inverse(denom)) % m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll a, b, n; cin >> a >> b >> n;

	for (ll i = 1; i < 1e7; ++i) {
		fac[i] = (i * fac[i-1]) % m;

		ll n = i;
		while (n >= 1) {
			if (n % 10 != a and n % 10 != b) {
				isgood[i] = false;
				break;
			}
			n /= 10;
		}
	}

	ll ans = 0;
	for (ll acnt = 0; acnt <= n; ++acnt) {
		ll bcnt = n - acnt;
		ll sum = acnt*a + bcnt*b;
		if (isgood[sum])
			ans = (ans + comb(n, acnt)) % m;
	}

	cout << ans << '\n';
	return 0;
}
