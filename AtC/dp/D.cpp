#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N,W, w[100],v[100], dp[100][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>W;
    for (ll i=0; i<N; i++)
        cin>>w[i]>>v[i];
    
    memset(dp, 0, sizeof dp);
    for (ll j=w[0]; j<=W; j++) dp[0][j] = v[0];
    for (ll i=1; i<N; i++) {
        for (ll j=1; j<=W; j++) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            if (j-w[i] >= 0) {
                dp[i][j] = max(
                    dp[i][j],
                    v[i] + dp[i-1][j-w[i]]
                );
            }
        }
    }

    cout << dp[N-1][W] << '\n';
    return 0;
}