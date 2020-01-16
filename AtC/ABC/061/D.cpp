#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll NEGINF=-(1LL<<63-1);
vector<vector<pair<ll,ll>>> g;
vector<bool> isInf;
vector<bool> visited;
vector<ll> scores;

void bf() {
	scores[1]=0;
	for (int i=0; i<g.size()-1; i++)
		for (int v=0; v<g.size(); v++)
			for (pair<ll,ll> p : g[v])
				scores[p.first] = max(scores[p.first], scores[v] + p.second);
}

void hasInfCycle() {
	for (int v=0; v<g.size(); v++)
		for (pair<ll,ll> p : g[v])
			if (scores[v] + p.second > scores[p.first])
				isInf[p.first] = true;
}

void dfs(int s) {
	visited[s]=true;
	isInf[s]=true;
	for (pair<ll,ll> p : g[s])
		if (!visited[p.first])
			dfs(p.first);
}

int main() {
	ll n,m; cin>>n>>m;
	g.resize(n+1);
	scores.resize(n+1,NEGINF);
	isInf.resize(n+1);
	visited.resize(n+1);
	for (ll i=0; i<m; i++) {
		ll a,b,c; cin>>a>>b>>c;
		g[a].push_back({b,c});
	}
	bf();
	hasInfCycle();
	for (int i=1; i<=n; i++)
		if (isInf[i]) dfs(i);

	if (isInf[1] or isInf[n]) cout << "inf" << endl;
	else cout << scores[n] << endl;
	return 0;
}
