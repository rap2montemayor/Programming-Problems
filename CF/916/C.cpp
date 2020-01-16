#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
	for (int i=2; i*i<=n; i++)
		if (n%i==0) return false;
	return true;
}

int main() {
	int n,m; cin>>n>>m;

	int mst=0, edges=0;
	vector<vector<pair<int,int>>> g(n+1);
	for (int i=2; i<=n; i++) {
		g[1].push_back({i,2});
		mst+=2;
		edges++;
	}
	g[1].back().second++;
	mst++;

	for (int i=2; i<=n; i++) {
		for (int j=i+1; j<=n; j++) {
			if (edges==m) break;
			g[i].push_back({j,104206969});
			edges++;
		}
		if (edges==m) break;
	}

	while (!isPrime(mst)) {
		g[1][0].second++;
		mst++;
	}

	cout << g[1].back().second << ' ' << mst << endl;
	for (int i=1; i<=n; i++)
		for (pair<int,int> p : g[i])
			cout << i << ' ' << p.first << ' ' << p.second << endl;
	return 0;
}
