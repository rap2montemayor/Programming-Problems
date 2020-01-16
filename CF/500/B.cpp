#include <bits/stdc++.h>
using namespace std;

vector<int> dfs(int s, vector<vector<int>> &g, vector<int> &component, vector<int> &p) {
	vector<int> res;
	for (int i=0; i<g.size(); i++) {
		if (g[s][i] and component[i]==-1) {
			component[i] = component[s];
			res.push_back(p[i]);
			for (int j : dfs(i,g,component,p))
				res.push_back(j);
		}
	}
	return res;
}

int main() {
	int n; cin>>n;
	vector<int> p(n);
	vector<vector<int>> a(n,vector<int>(n));

	for (int i=0; i<n; i++)
		cin>>p[i];
	for (int i=0; i<n; i++) {
		string s; cin>>s;
		for (int j=0; j<n; j++) {
			a[i][j] = s[j] - '0';
			a[j][i] = s[j] - '0';
		}
	}

	vector<int> component(n,-1), index(n);
	vector<vector<int>> comps(n);
	for (int i=0; i<n; i++) {
		if (component[i] == -1) {
			component[i] = i;
			comps[i] = dfs(i,a,component,p);
			comps[i].push_back(p[i]);
			sort(comps[i].begin(), comps[i].end());
		}
	}

	for (int i : component) {
		cout << comps[i][index[i]] << ' ';
		index[i]++;
	}
	cout << endl;

	return 0;
}
