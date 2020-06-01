#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N,W,V=0, w[100],v[100], dp[100][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>W;
    for (ll i=0; i<N; i++) cin>>w[i]>>v[i];
    for (ll i : v) V += i;

    for (ll i=0; i<N; i++) {
        for (ll j=0; j<=V; j++)
            dp[i][j] = 1e12;
        dp[i][0] = 0;
    }

    dp[0][v[0]] = w[0];
    for (ll idx=1; idx<N; idx++) {
    for (ll val=1; val<=V; val++) {
        if (dp[idx-1][val] != -1) {
            dp[idx][val] = dp[idx-1][val];
        }
        if (val-v[idx] >= 0) {
            if (dp[idx-1][val-v[idx]] != -1) {
                dp[idx][val] = min(dp[idx][val], w[idx] + dp[idx-1][val-v[idx]]);
            }
        }
    }}

    ll ans;
    for (ll val=V; val>=0; val--) {
        if (dp[N-1][val] <= W) {
            ans = val;
            break;
        }
    }
    
    cout << ans << endl;
    return 0;
}