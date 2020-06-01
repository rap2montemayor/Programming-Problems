#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e9;
vvi dp(51, vi(51));
vi cuts(51);

int solve(int l, int r, int n) {
    if (dp[l][r] != INF) return dp[l][r];
    if (r-l <= 1) dp[l][r] = 0;
    else {
        for (int i = 1; i <= n; i++) {
            if (i <= l or i >= r) continue;
            dp[l][r] = min(
                dp[l][r],
                cuts[r] - cuts[l] + solve(l, i, n) + solve(i, r, n)
            );
        }
    }

    return dp[l][r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int l; cin >> l;
    while (l != 0) {
        for (int i = 0; i < 50; ++i)
            fill(dp[i].begin(), dp[i].end(), INF);

        int n; cin>>n;
        for (int i = 1; i <= n; ++i)
            cin >> cuts[i];

        cuts[0] = 0, cuts[n+1] = l;
        cout << "The minimum cutting is "
             << solve(0, n+1, n) << ".\n"; 
        cin >> l;
    }
    return 0;
}