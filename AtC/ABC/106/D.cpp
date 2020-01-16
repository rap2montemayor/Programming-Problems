#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m,q; cin>>n>>m>>q;
	vector<vector<int>> trains(n+2,vector<int>(n+2));
	while (m--) {
		int l,r; cin>>l>>r;
		trains[l][r]++;
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			trains[i][j] = trains[i][j]
						 + trains[i-1][j]
						 + trains[i][j-1]
						 - trains[i-1][j-1];
		}
	}

	while (q--) {
		int pi, qi; cin>>pi>>qi;
		//between [pi][pi] and [qi][qi]
		int ans = trains[qi][qi]
				- trains[pi-1][qi]
				- trains[qi][pi-1]
				+ trains[pi-1][pi-1];
		cout << ans << endl;
	}

	return 0;
}
