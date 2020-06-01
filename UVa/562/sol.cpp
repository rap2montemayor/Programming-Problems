#include <bits/stdc++.h>
using namespace std;

bool dp[101][50001];
int coins[101], n, t;
void solve(int idx, int cur) {
    if (idx>=n+1) return;
    if (dp[idx][cur]) return;
    dp[idx][cur]=true;

    solve(idx+1,cur+coins[idx]);
    solve(idx+1,cur);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    while (t--) {
        cin>>n;
        int total = 0;
        for (int i=0; i<n; ++i) cin>>coins[i];
        for (int i=0; i<n; ++i) total += coins[i];
        memset(dp, false, sizeof(dp));
        solve(0,0);

        int ans = 1e9;
        for (int i=0; i<=total; ++i)
            if (dp[n][i]) ans = min(ans,abs(total-i-i));
        cout << ans << '\n';
    }
}