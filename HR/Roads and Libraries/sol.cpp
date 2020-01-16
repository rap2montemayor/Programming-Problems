#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dfs(ll s, vector<vector<ll>> &g, vector<bool> &visited) {
	//returns number of edges used
	ll edges = 0;
	visited[s]=true;
	for (ll i : g[s])
		if (!visited[i])
			edges += dfs(i,g,visited) + 1;
	return edges;
}
	
vector<ll> getComponents(vector<vector<ll>> &g) {
	vector<bool> visited(g.size());
	vector<ll> comps;
	for (ll i=1; i<g.size(); i++) {
		if (!visited[i]) {
			comps.push_back(i);
			dfs(i,g,visited);
		}
	}
	return comps;
}

ll countMinEdges(ll s, vector<vector<ll>> &g) {
	vector<bool> visited(g.size());
	return dfs(s,g,visited);
}

int main() {
	ll q; cin>>q;
	while (q--) {
		ll n,m,clib,croad; cin>>n>>m>>clib>>croad;
		vector<vector<ll>> g(n+1);
		for (ll i=0; i<m; i++) {
			ll u,v; cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		vector<ll> components = getComponents(g);
		ll minEdges = 0;
		for (ll i : components) minEdges += countMinEdges(i,g);

		ll ans;
		if (minEdges*croad+components.size()*clib < n*clib)
			ans = minEdges*croad+components.size()*clib;
		else
			ans = n*clib;
		cout << ans << endl;
	}
	return 0;
}
