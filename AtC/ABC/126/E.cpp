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
		if (xp == yp) return false;
		if (p[xp] > p[yp]) swap(xp, yp);
		p[xp] += p[yp], p[yp] = xp;
		return true;
	}

	int count() {
		int res = 0;
		for (int i : p)
			if (i < 0) ++res;
		return res;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;
	union_find uf(n+1);

	for (int i = 0; i < m; ++i) {
		int x, y, z; cin >> x >> y >> z;
		uf.unite(x, y);
	}

	cout << uf.count() - 1 << '\n';
	return 0;
}