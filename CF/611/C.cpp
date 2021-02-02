#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<string> g;
vector<vector<int>> doms, vcross, hcross;

void doallthesetupstuff() {
	for (int i = 1; i < h; ++i) {
		for (int j = 1; j < w; ++j) {
			doms[i][j] = doms[i][j-1] + doms[i-1][j] - doms[i-1][j-1];
			vcross[i][j] = vcross[i][j-1];
			hcross[i][j] = hcross[i-1][j];

			if (g[i][j] == '.' and g[i-1][j] == '.')
				++doms[i][j], ++vcross[i][j];
			if (g[i][j] == '.' and g[i][j-1] == '.')
				++doms[i][j], ++hcross[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> h >> w;
	++h, ++w;
	g = vector<string>(h);
	doms = vcross = hcross = vector<vector<int>>(h, vector<int>(w));
	g[0] = string(w, '#');
	for (int i = 1; i < h; ++i) {
		cin >> g[i];
		g[i] = "#" + g[i];
	}

	doallthesetupstuff();
	int q, r1, c1, r2, c2;
	cin >> q;
	while (q--) {
		cin >> r1 >> c1 >> r2 >> c2;
		int ans =
			doms[r2][c2] - doms[r2][c1-1] - doms[r1-1][c2] + doms[r1-1][c1-1]
			+ vcross[r1][c1-1] - vcross[r1][c2]
			+ hcross[r1-1][c1] - hcross[r2][c1];
		cout << ans << '\n';
	}
	return 0;
}

