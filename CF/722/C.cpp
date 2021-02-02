#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct union_find {
	vector<ll> p;

	union_find(ll n) : p(n, -1) { }

	ll find(ll x) {
		return p[x] < 0 ? x : p[x] = find(p[x]);
	}

	bool unite(ll x, ll y) {
		ll xp = find(x), yp = find(y);
		if (xp == yp) return false;
		if (p[xp] > p[yp]) swap(xp, yp);
		p[xp] += p[yp];
		p[yp] = xp;
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll n, cur = 0; cin >> n;
	vector<ll> a(n+2), b(n+2), val(n+2), ans(1);
	vector<bool> rip(n+2, true);
	union_find seg(n+2);
	for (ll i = 0; i < n; ++i) cin >> a[i+1];
	for (ll i = 0; i < n; ++i) cin >> b[i+1];
	
	for (ll i = n; i > 1; --i) {
		ll idx = b[i];
		rip[idx] = false;
		if (rip[idx-1] and rip[idx+1]) {
			cur = max(cur, a[idx]);
			ans.push_back(cur);	
			continue;
		}

		ll newval = a[idx];
		if (not rip[idx-1]) {
			newval += a[seg.find(idx-1)];
			seg.unite(idx, idx-1);
		}
		if (not rip[idx+1]) {
			newval += a[seg.find(idx+1)];
			seg.unite(idx, idx+1);
		}

		a[seg.find(idx)] = newval;
		cur = max(cur, newval);
		ans.push_back(cur);
	}

	reverse(ans.begin(), ans.end());
	for (ll i : ans)
		cout << i << '\n';
	return 0;
}