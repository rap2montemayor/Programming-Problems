#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	vector<set<int>> g(n+1);
	queue<int> seq;
	vector<bool> visited(n+1);

	for (int i=0; i<n-1; i++) {
		int a,b; cin>>a>>b;
		g[a].insert(b);
		g[b].insert(a);
	}
	for (int i=0; i<n; i++) {
		int x; cin>>x;
		seq.push(x);
	}
	
	bool valid=true;
	queue<int> q;
	q.push(seq.front());
	visited[seq.front()]=true;
	seq.pop();
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		int r = g[v].size();
		if (v!=1) r--;
		for (int i=0; i<r; i++) {
			if (g[v].count(seq.front())) {
				q.push(seq.front());
				visited[seq.front()]=true;
				seq.pop();
			}
			else {
				valid=false;
				break;
			}
		}

		if (!valid) break;
	}

	for (int i=1; i<=n; i++) if (!visited[i]) valid=false;
	if (valid) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
