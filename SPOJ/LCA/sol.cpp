#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct graph {
	int n, logn, *par, *dep, *first, *lg, **spt;
	vi *adj, euler;
	
	graph(int n) : n(n) {
		adj = new vi[n];
		par = new int[n];
		dep = new int[n];
		first = new int[n];

		lg = new int[n*3+1];
		lg[0] = lg[1] = 0;
		for (int i = 2; i <= n*3; ++i)
			lg[i] = lg[i >> 1] + 1;

		spt = new int*[n*3];
		for (int i = 0; i < n*3; ++i)
			spt[i] = new int[lg[n*3]+1];
	}

	void reset() {
		for (int i = 0; i < n; ++i)
			adj[i].clear();
		euler.clear();
	}
	
	void add_edge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void dfs(int u, int p, int d) {
		dep[u] = d; par[u] = p;
		first[u] = euler.size();
		euler.push_back(u);
		for (int v : adj[u]) {
			if (v != p) {
				dfs(v, u, d+1);
				euler.push_back(u);
			}
		}
	}

	void prep_lca(int root=0) {
		dfs(root, root, 0);

		int en = euler.size();
		for (int i = 0; i < en; ++i)
			spt[i][0] = euler[i];
		
		for (int k = 0; (2 << k) <= en; ++k)
			for (int i = 0; i + (2 << k) <= en; ++i)
				if (dep[spt[i][k]] < dep[spt[i+(1<<k)][k]])
					spt[i][k+1] = spt[i][k];
				else
					spt[i][k+1] = spt[i+(1<<k)][k];
	}

	int lca(int u, int v) {
		int a = first[u], b = first[v];
		if (a > b) swap(a, b);

		int k = lg[b-a+1], ba = b - (1 << k) + 1;
		if (dep[spt[a][k]] < dep[spt[ba][k]])
			return spt[a][k];
		else
			return spt[ba][k];
	}
};

graph g(1001);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		g.reset();
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) {
			int m; cin >> m;
			for (int j = 0; j < m; ++j) {
				int v; cin >> v;
				g.add_edge(i, v);
			}
		}

		cout << "Case " << t << ":\n";
		g.prep_lca(1);
		int q; cin >> q;
		while (q--) {
			int u, v; cin >> u >> v;
			cout << g.lca(u, v) << '\n';
		}
	}
	return 0;
}