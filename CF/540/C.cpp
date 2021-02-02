#include <bits/stdc++.h>
using namespace std;

int dr[] = {0, 0, 1, -1}, dc[] = {1, -1, 0, 0};

bool reachable(int r1, int c1, int r2, int c2, vector<string> &g) {
	int n = g.size(), m = g[0].size();
	vector<vector<bool>> vis(n, vector<bool>(m));
	queue<pair<int,int>> q;
	q.push({r1, c1});
	vis[r1][c1] = true;

	while (not q.empty()) {
		int r = q.front().first, c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nr = r+dr[i], nc = c+dc[i];
			bool valid = nr >= 0 and nr < n and nc >= 0 and nc < m;
			if (not valid) continue;

			if (nr == r2 and nc == c2) {
				vis[nr][nc] = true;
				break;
			}
			if (not vis[nr][nc] and g[nr][nc] == '.') {
				vis[nr][nc] = true;
				q.push({nr, nc});
			}
		}

		if (vis[r2][c2]) break;
	}

	return vis[r2][c2];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;
	vector<string> g(n);
	for (int i = 0; i < n; ++i)
		cin >> g[i];
	int r1, c1, r2, c2; 
	cin >> r1 >> c1 >> r2 >> c2;
	--r1, --c1, --r2, --c2;

	// ayt fuck these edge cases
	bool ans = false;
	int empty = 0;
	for (int i = 0; i < 4; ++i) {
		int nr = r2+dr[i], nc = c2+dc[i];
		bool valid = nr >= 0 and nr < n and nc >= 0 and nc < m;
		if (not valid) continue;
		if (g[nr][nc] == '.') ++empty;
		else if (nr == r1 and nc == c1) ++empty;
	}

	if (reachable(r1, c1, r2, c2, g)) {
		bool same = r1 == r2 and c1 == c2;
		if (same and g[r2][c2] == 'X')
			ans = empty >= 1;
		else if (same and g[r2][c2] == '.')
			ans = empty >= 1;
		else if (not same and g[r2][c2] == 'X')
			ans = empty >= 1;
		else
			ans = empty >= 2;
	}

	if (ans) cout << "YES\n";
	else cout << "NO\n";
				
	return 0;
}