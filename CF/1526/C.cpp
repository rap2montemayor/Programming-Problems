#include <bits/stdc++.h>
using namespace std;

int n, a[2001], dp[2001][2001] = {0};
int solve() {
    //idx, taken
    int ans = 0;
    for (int i = 0; i < n; ++i)
        dp[0][i] = max(0, a[0]);
    for (int j = 1; j < n; ++j) {
        bool good = false;
        for (int i = 1; i < n; ++i) {
            if (dp[i-1][j-1] + a[i] >= 0) {
                good = true;
                dp[i][j] = max(
                    dp[i-1][j-1] + a[i],
                    dp[i-1][j]
                );
            }
            else dp[i][j] = dp[i-1][j];
        }
        if (good) ans = j;
    }

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << solve() << '\n';

    return 0;
}