#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> distances;
vector<bool> visited;
vector<vector<pair<ll,ll>>> adjlist;

void dfs(ll start, ll depth) {
	distances[start]=depth;
	visited[start]=true;
	for (pair<ll,ll> p : adjlist[start])
		if (!visited[p.first])
			dfs(p.first,depth+p.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n; cin>>n;
	adjlist.resize(n+1);
	distances.resize(n+1);
	visited.resize(n+1);
	for (ll i=0; i<n-1; i++) {
		ll a,b,c; cin>>a>>b>>c;
		adjlist[a].push_back({b,c});
		adjlist[b].push_back({a,c});
	}

	ll q,k; cin>>q>>k;
	dfs(k,0);
	while (q--) {
		ll x,y; cin>>x>>y;
		cout << distances[x] + distances[y] << endl;
	}
	return 0;
}

