#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m; cin >> m;
    while (m--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < 0)
                a[i] *= -1;
            a[i] %= k;
        }

        vector<vector<bool>> dp(n, vector<bool>(k, false));
        dp[0][a[0]] = true;
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < k; j++) {
                if (dp[i][j]) {
                    int res1 = (j + k + a[i+1]) % k;
                    int res2 = (j + k - a[i+1]) % k;
                    dp[i+1][res1] = dp[i+1][res2] = true;
                }
            }
        }

        if (dp[n-1][0]) cout << "Divisible\n";
        else cout << "Not divisible\n";
    }
    return 0;
}
