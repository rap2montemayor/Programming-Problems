#include <bits/stdc++.h>
using namespace std;

int t, n, m, di[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dj[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<vector<bool>> grid(1000, vector<bool>(1000)), vis(1000, vector<bool>(1000));
pair<int,int> S, F;

int solve() {
	queue<pair<int,pair<int,int>>> q;
	vis[S.first][S.second] = true;
	q.push({0,S});

	while (!q.empty()) {
		int moves = q.front().first,
			i = q.front().second.first,
			j = q.front().second.second;
		q.pop();

		for (int x = 0; x < 8; ++x) {
			int ii = i, jj = j;
			while (true) {
				ii += di[x], jj += dj[x];
				bool valid = ii >= 0 and ii < n and jj >= 0 and jj < m;
				if (not valid or not grid[ii][jj]) break;

				if (valid and !vis[ii][jj]) {
					if (F.first == ii and F.second == jj)
						return moves+1;
					vis[ii][jj] = true;
					q.push({moves+1, {ii, jj}});
				}
			}
		}
	}

	return -1;
} 

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		char c;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf(" %c ", &c);
				grid[i][j] = true;
				vis[i][j] = false;
				if (c == 'S') S = {i, j};
				else if (c == 'F') F = {i, j};
				else if (c == 'X') grid[i][j] = false;
			} 
		}
		printf("%d\n", solve());
	}

	return 0;
}
