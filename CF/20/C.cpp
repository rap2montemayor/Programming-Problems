#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = ~(1LL<<63);

void dijkstra(ll s, vector<vector<pair<ll,ll>>> &g, vector<ll> &dist, vector<ll> &sp) {
	for (ll i=0; i<g.size(); i++)
		dist[i]=INF;
	dist[s] = 0;

	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
	pq.push({0,s});

	while (!pq.empty()) {
		ll u=pq.top().second;
		ll d=pq.top().first;
		pq.pop();
		if (dist[u]<d) continue;
		dist[u] = d;
		for (pair<ll,ll> p : g[u]) {
			ll v = p.first;
			ll w = p.second;
			if (dist[v] > dist[u]+w) {
				dist[v] = dist[u]+w;
				sp[v] = u;
				pq.push({dist[v],v});
			}
		}
	}
}

int main() {
	ll n,m; cin>>n>>m;
	vector<vector<pair<ll,ll>>> g(n+1);
	for (ll i=0; i<m; i++) {
		ll a,b,w; cin>>a>>b>>w;
		g[a].push_back({b,w});
		g[b].push_back({a,w});
	}
	vector<ll> dist(g.size()), sp(g.size());
	dijkstra(1,g,dist,sp);
	
	vector<ll> path({n});
	ll current = n;

	if (dist[n]==INF) {
		cout << -1 << endl;
		return 0;
	}
	while (current != 1) {
		current = sp[current];
		path.push_back(current);
	}
	reverse(path.begin(), path.end());
	for (ll i : path) cout << i << ' ';
	cout << endl;
	return 0;
}
