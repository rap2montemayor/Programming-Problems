#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m,q; cin>>n>>m>>q;
	vector<vector<int>> g(n+m);
	for (int i=0; i<q; i++) {
		int r,c; cin>>r>>c;
		r--; c--; c+=n;
		g[r].push_back(c);
		g[c].push_back(r);
	}

	//get # of connected components
	vector<bool> visited(n+m);
	int comps=0;
	for (int i=0; i<n+m; i++) {
		if (!visited[i]) {
			comps++;
			visited[i]=true;
			queue<int> q({i});

			while (!q.empty()) {
				int v=q.front();
				q.pop();
				for (int u : g[v]) {
					if (!visited[u]) q.push(u);
					visited[u]=true;
				}
			}
		}
	}

	cout << comps-1 << endl;
	return 0;
}
