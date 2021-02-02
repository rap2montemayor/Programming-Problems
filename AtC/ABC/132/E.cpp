#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kenkenpaify(vector<vector<int>> &g, int s) {
	vector<vector<int>> g2(g.size());
	vector<vector<bool>> vis (4, vector<bool>(g.size()));
	vis[3][s] = true;
 
	//u, v, path len
	queue<vector<int>> q;
	q.push({s, s, 3});
	while (not q.empty()) {
		int u = q.front()[0], v = q.front()[1], rem = q.front()[2];
		q.pop();
		
		if (rem == 0) {
			g2[u].push_back(v);
			if (not vis[3][v]) {
				q.push({v, v, 3});
				vis[3][v] = true;
			}
			continue;
		}
 
		for (int i : g[v]) {
			if (not vis[rem-1][i]) {
				q.push({u, i, rem-1});
				vis[rem-1][i] = true;
			}
		}
	}
 
	return g2;
}

int getdist(vector<vector<int>> &g, int s, int t) {
	vector<int> dist(g.size(), -1);

	queue<pair<int,int>> q;
	q.push({s, 0});
	dist[s] = 0;
	while (not q.empty()) {
		int u = q.front().first, d = q.front().second;
		q.pop();

		for (int i : g[u]) {
			if (dist[i] == -1)
				q.push({i, d+1});
			dist[i] = d+1;
		}
	}

	return dist[t];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, s, t;
	cin >> n >> m;
	
	vector<vector<int>> g(n+1);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
	}
	cin >> s >> t;

	vector<vector<int>> g2 = kenkenpaify(g, s);
	cout << getdist(g2, s, t) << '\n';
	return 0;
}
