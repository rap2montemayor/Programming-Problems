#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+7;

void fw(vector<vector<int>> &adj) {
	int n = adj.size();
	for (int k=0; k<n; k++) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (adj[i][k]==INF or adj[k][j]==INF) continue;
				adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
			}
		}
	}
}

int getDistance(vector<int> &r, vector<vector<int>> &adj) {
	int result=0;
	for (int i=1; i<r.size(); i++)
		result += adj[r[i]][r[i-1]];
	return result;
}

int main() {
	int n,m,R; cin>>n>>m>>R;
	vector<int> r(R);
	vector<vector<int>> adj(n+1,vector<int>(n+1,INF));
	for (int i=0; i<R; i++) cin>>r[i];
	for (int i=0; i<m; i++) {
		int a,b,c; cin>>a>>b>>c;
		adj[a][b] = c;
		adj[b][a] = c;
	}
	fw(adj);
	sort(r.begin(), r.end());

	int ans = getDistance(r,adj);
	while (next_permutation(r.begin(),r.end())) {
		int temp = getDistance(r,adj);
		if (temp<ans) ans=temp;
	}
	cout << ans << endl;
	return 0;
}
