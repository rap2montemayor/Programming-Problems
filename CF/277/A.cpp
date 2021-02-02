#include <bits/stdc++.h>
using namespace std;

struct union_find {
	vector<int> p;
	
	union_find(int n) : p(n, -1) {}
	
	int find(int x) {
		return p[x] < 0 ? x : p[x] = find(p[x]);
	}
	
	bool unite(int x, int y) {
		int xp = find(x), yp = find(y);
		if (xp == yp)
			return false;
		if (p[xp] > p[yp])
			swap(xp, yp);
		p[xp] += p[yp];
		p[yp] = xp;
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;
	union_find uf(n+m);
	for (int i = 0; i < n; ++i) {
		int langs; cin >> langs;
		for (int j = 0; j < langs; ++j) {
			int x; cin >> x;
			uf.unite(i, n + x - 1);
		}
	}

	int ans = -1;
	int nolangs = 0;
	for (int i = 0; i < n; ++i) {
		if (uf.p[i] < 0) ++ans;
		if (uf.p[i] == -1) ++nolangs;
	}

	if (nolangs == n) ++ans;
	cout << ans << '\n';
	
	return 0;
}