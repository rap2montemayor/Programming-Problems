#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

ll gettotalweight(vvii &g) {
	//already doubled
	ll res = 0;
	for (ll i = 0; i < g.size(); ++i)
		for (pair<ll, ll> &p : g[i])
			res += p.second;
	return res;
}

vi getleaves(vvii &g) {
	vi leaves;
	for (ll i = 1; i < g.size(); ++i)
		if (g[i].size() == 1)
			leaves.push_back(i);
	return leaves;
}

vi propagateweights(vvii &g) {
	queue<ll> q;
	vi weights(g.size(), -1);

	q.push(0);
	weights[0] = 0;
	while (not q.empty()) {
		ll u = q.front();
		q.pop();
		for (ii &p : g[u]) {
			ll v = p.first, w = p.second;
			if (weights[v] != -1) continue;
			weights[v] = weights[u] + w;
			q.push(v);
		}
	}

	return weights;
}

ll solve(vvii &g) {
	ll tot = gettotalweight(g);
	ll ans = tot;
	vi leaves = getleaves(g), weights = propagateweights(g);
	for (ll i : leaves)
		ans = min(ans, (tot) - weights[i]);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll n; cin >> n;
	vvii g(n);
	for (ll i = 0; i < n-1; ++i) {
		ll u, v, w; cin >> u >> v >> w;
		--u, --v;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	cout << solve(g);
	return 0;
}
