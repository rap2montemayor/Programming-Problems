#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

ll n;
vi a, cnt, dp;
ll solve(ll idx) {
    if (idx >= cnt.size()) return 0;
    if (dp[idx] != -1) return dp[idx];

    ll ans;
    ans = max(
        idx*cnt[idx] + solve(idx+2),
        solve(idx+1)
    );

    dp[idx] = ans;
    return dp[idx];
}


int main() {
    cin>>n;
    a = vi(n);
    ll m=-1;
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i : a) m = max(m,i);

    cnt = vi(m+1);
    dp = vi(m+1,-1);
    for (ll i : a) cnt[i]++;

    cout << solve(0) << endl;
    return 0;
}