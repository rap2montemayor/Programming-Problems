#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
const int INF = 1e9+7;

int bfs(int s, int t, vvi &adj, vvi &capacity, vi &parent) {
	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue<pair<int, int>> q;
	q.push({s,INF});

	while (!q.empty()) {
		int cur = q.front().first;
		int flow = q.front().second;
		q.pop();

		for (int next : adj[cur]) {
			if (parent[next] == -1 and capacity[cur][next]) {
				parent[next] = cur;
				int new_flow = min(flow,capacity[cur][next]);
				if (next == t)
					return new_flow;
				q.push({next,new_flow});
			}
		}
	}

	return 0;
}

int maxflow(int s, int t, vvi &adj, vvi &capacity) {
	int flow = 0, new_flow;
	vi parent(adj.size());

	while (new_flow = bfs(s,t,adj,capacity,parent)) {
		flow += new_flow;
		int cur=t;
		while (cur!=s) {
			int prev=parent[cur];
			capacity[prev][cur] -= new_flow;
			capacity[cur][prev] += new_flow;
			cur=prev;
		}
	}

	return flow;
}

int main() {
	int n; cin>>n;
	int network=0;
	while (n!=0) {
		int s,t,c; cin>>s>>t>>c;
	
		vvi adj(n), capacity(n,vi(n));
		for (int i=0; i<c; i++) {
			int u,v,cap; cin>>u>>v>>cap;
			u--; v--;
		 	adj[u].push_back(v);
		 	adj[v].push_back(u);
		 	capacity[u][v] += cap;
		 	capacity[v][u] += cap;
		}
	
		s--; t--;
		cout << "Network " << ++network << endl;
		cout << "The bandwidth is " << maxflow(s,t,adj,capacity) << ".\n\n";
		cin>>n;
	}
	return 0;
}
