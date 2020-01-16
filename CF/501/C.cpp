#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	vector<vector<int>> prop(n);
	vector<pair<int,int>> edges;
	deque<int> v;
	for (int i=0; i<n; i++) {
		int deg, s; cin>>deg>>s;
		prop[i] = {deg,s};
		if (deg==1) v.push_back(i);
	}

	while (!v.empty()) {
		int idx = v.front();
		int deg = prop[idx][0];
		int s = prop[idx][1];

		if (deg == 1) {
			prop[s][0]--;
			prop[s][1]^=idx;
			edges.push_back({idx,s});
			v.pop_front();

			if (prop[s][0]==1) v.push_back(s);
		}
		else v.pop_front();
	}

	cout << edges.size() << endl;
	for (pair<int,int> p : edges) cout << p.first << ' ' << p.second << endl;
	return 0;
}
