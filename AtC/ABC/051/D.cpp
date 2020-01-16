#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7; 

int main() {
	int n,m; cin>>n>>m;
	vector<vector<int>> adj(n+1,vector<int>(n+1,INF));
	vector<vector<int>> path(n+1,vector<int>(n+1,-1));
	vector<vector<int>> used(n+1,vector<int>(n+1));
	vector<vector<int>> edges(m);
	for (int i=0; i<m; i++) {
		int a,b,c; cin>>a>>b>>c;
		edges[i] = {a,b,c};
		adj[a][b] = c;
		adj[b][a] = c;
		path[a][b] = b;
		path[b][a] = a;
	}
	for (int i=0; i<=n; i++) {
		adj[i][i]=0;
		path[i][i]=i;
	}

	for (int k=0; k<=n; k++) {
		for (int i=0; i<=n; i++) {
			for (int j=0; j<=n; j++) {
				if (adj[i][k]==INF or adj[k][j]==INF) continue;
				if (adj[i][j] > adj[i][k]+adj[k][j])
					path[i][j] = path[i][k];
				adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
			}
		}
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			int current=i;
			while (current != j) {
				used[current][path[current][j]]=1;
				current = path[current][j];
			}
		}
	}

	int ans=0;
	for (vector<int> v : edges)
		if (!used[v[0]][v[1]]) ans++;
	cout << ans << endl;
	return 0;
}


