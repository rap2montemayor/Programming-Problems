#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9+7;

int main() {
	int n,ma,mb; cin>>n>>ma>>mb;
	vector<int> a(n),b(n),c(n);
	for (int i=0; i<n; i++)
		cin>>a[i]>>b[i]>>c[i];

	int dp[n+1][500][500];
	for (int i=0; i<=n; i++)
	for (int j=0; j<500; j++)
	for (int k=0; k<500; k++)
		dp[i][j][k]=inf;
	dp[0][0][0]=0;

	for (int i=0; i<n; i++)
	for (int j=0; j<500; j++)
	for (int k=0; k<500; k++) {
		if (dp[i][j][k]==inf) continue;
		dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
		dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k]+c[i]);
	}

	int ans=inf;
	for (int i=0; i<=n; i++)
	for (int j=1; j<500; j++)
	for (int k=1; k<500; k++)
		if (j*mb == k*ma)
			ans = min(ans,dp[i][j][k]);
	
	if (ans<inf) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}
