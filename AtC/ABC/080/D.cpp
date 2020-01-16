#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, C; cin>>n>>C;
	vector<int> s(n), t(n), c(n);
	vector<vector<int>> channels(31,vector<int>(100002));
	for (int i=0; i<n; i++) {
		cin>>s[i]>>t[i]>>c[i];
		for (int j=s[i]; j<=t[i]; j++) {
			channels[c[i]][j]++;
		}
	}

	int ans=0;
	for (int i=1; i<=100000; i++) {
		int current=0;
		for (int j=0; j<=30; j++) {
			if (channels[j][i]) {
				current++;
			}
		}
		if (current>ans) {
			ans=current;
		}
	}

	cout << ans << endl;
	return 0;
}
