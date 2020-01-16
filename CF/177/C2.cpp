#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>> &g, set<int> &nodes, vector<bool> &visited) {
	visited[v]=true;
	nodes.insert(v);
	for (int i : g[v])
		if (!nodes.count(i))
			dfs(i,g,nodes,visited);
}

int main() {
	int n; cin>>n;
	vector<vector<int>> friends(n+1);
	vector<vector<int>> dislike(n+1);

	int k; cin>>k;
	for (int i=0; i<k; i++) {
		int u,v; cin>>u>>v;
		friends[u].push_back(v);
		friends[v].push_back(u);
	}
	int m; cin>>m;
	for (int i=0; i<m; i++) {
		int u,v; cin>>u>>v;
		dislike[u].push_back(v);
		dislike[v].push_back(u);
	}

	vector<set<int>> components;
	vector<bool> visited(n+1);
	for (int i=1; i<=n; i++) {
		if (!visited[i]) {
			components.push_back(set<int>());
			dfs(i,friends,components.back(),visited);
		}
	}

	int ans=0;
	for (set<int> st : components) {
		bool canInvite = true;
		for (int i : st) {
			for (int v : dislike[i]) {
				if (st.count(v)) {
					canInvite=false;
					break;
				}
			}
			if (!canInvite) break;
		}
		if (canInvite) ans=max(ans,int(st.size()));
	}

	cout << ans << endl;
	return 0;
}
