#include <bits/stdc++.h>
using namespace std;

int mdist(pair<int, int> p1, pair<int, int> p2) {
	return abs(p2.first - p1.first) + abs(p2.second - p1.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (int t = 0; t < T; ++t) {
		int X, Y, sx, sy, n;
		cin >> X >> Y >> sx >> sy >> n;
		vector<pair<int,int>> coords(n);
		for (int i = 0; i < n; ++i)
			cin >> coords[i].first >> coords[i].second;

		int res = 1e9;
		vector<int> path(n);
		iota(path.begin(), path.end(), 0);
		do {
			int cur = 0;
			cur += mdist({sx, sy}, coords[path[0]]);
			cur += mdist({sx, sy}, coords[path[n-1]]);
			for (int i = 0; i < n-1; ++i)
				cur += mdist(coords[path[i]], coords[path[i+1]]);

			res = min(cur, res);
		} while (next_permutation(path.begin(), path.end()));

		cout << "The shortest path has length ";
		cout << res << '\n';
	}

	return 0;
}