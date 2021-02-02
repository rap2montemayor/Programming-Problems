#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> piii;

bool comp(piii &p1, piii &p2) {
	pii a = p1.second, b = p2.second;
	return a.first*a.second + b.first*(a.second+b.second)
		<= b.first*b.second + a.first*(a.second+b.second);
}

void sortpls(vector<piii> &v, int l, int r) {
	if (l+1 >= r) return;

	int m = (l+r) / 2;
	sortpls(v, l, m);
	sortpls(v, m, r);

	vector<piii> lh(m-l), rh(r-m);
	for (int i = l; i < m; ++i)
		lh[i-l] = v[i];
	for (int i = m; i < r; ++i)
		rh[i-m] = v[i];

	int idx = l;
	l = 0, r = 0;
	while (l < lh.size() and r < rh.size()) {
		if (comp(lh[l], rh[r])) {
			v[idx] = lh[l];
			++idx, ++l;
		}
		else {
			v[idx] = rh[r];
			++idx, ++r;
		}
	}
	while (l < lh.size()) {
		v[idx] = lh[l];
		++idx, ++l;
	}
	while (r < rh.size()) {
		v[idx] = rh[r];
		++idx, ++r;
	}
}

ll eval(vector<piii> &v) {
	ll time = 0, ans = 0;
	for (ll i = 0; i < v.size(); ++i) {
		time += v[i].second.second;
		ans += time*v[i].second.first;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		vector<piii> v(n);
		for (ll i = 0; i < n; ++i) {
			v[i].first = i+1;
			cin >> v[i].second.first;
		}
		for (ll i = 0; i < n; ++i)
			cin >> v[i].second.second;

		sortpls(v, 0, n);
		cout << eval(v) << '\n';
		for (piii p : v)
			cout << p.first << ' ';
		cout << '\n';
	}
	return 0;
}
