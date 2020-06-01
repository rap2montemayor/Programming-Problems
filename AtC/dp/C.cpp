#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin>>n;
    int acts[n][3], dp[n][4];

    memset(dp, -1, sizeof dp);
    for (int i=0; i<n; i++) cin>>acts[i][0]>>acts[i][1]>>acts[i][2];
    for (int i=0; i<3; i++) dp[n-1][i] = acts[n-1][i];

    for (int day=n-2; day>=0; day--) {
        for (int act=0; act<3; act++) {
            for (int next=0; next<3; next++) {
                if (act==next) continue;
                dp[day][act] = max(
                    dp[day][act],
                    acts[day][act] + dp[day+1][next]
                );
            }
        }
    }

    int ans = max({ dp[0][0], dp[0][1], dp[0][2] });
    cout << ans << '\n';
    return 0;
}