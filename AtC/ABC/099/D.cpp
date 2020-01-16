#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,C; cin>>N>>C;
	vector<vector<int>> d(C+1,vector<int>(C+1));
	vector<vector<int>> c(N+1,vector<int>(N+1));
	for (int i=1; i<=C; i++)
		for (int j=1; j<=C; j++)
			cin>>d[i][j];

	vector<vector<int>> groups(3,vector<int>(C+1));
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			cin>>c[i][j];
			groups[(i+j)%3][c[i][j]]++;
		}
	}

	int ans = 1e9+7;
	for (int i=1; i<=C; i++) {
		for (int j=1; j<=C; j++) {
			if (i==j) continue;
			for (int k=1; k<=C; k++) {
				if (k==i or k==j) continue;
				int wrong=0;
				for (int l=1; l<=C; l++) {
					wrong += groups[0][l]*d[l][i];
					wrong += groups[1][l]*d[l][j];
					wrong += groups[2][l]*d[l][k];
				}
				if (wrong < ans) ans = wrong;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
