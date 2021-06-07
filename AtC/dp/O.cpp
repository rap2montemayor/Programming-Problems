#include <bits/stdc++.h>
using namespace std;

int n, a[21][21], dp[1<<21] = {0}, MOD = 1e9+7;

int countbits(int mask) {
    int res = 0;
    for (int i = 0; i < n; ++i)
        if (mask & (1<<i)) ++res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    dp[(1<<n)-1] = 1;
    for (int mask = (1<<n)-1; mask >= 0; --mask) {
        int i = countbits(mask);
        for (int j = 0; j < n; ++j)
            if (a[i][j] and not (mask & (1<<j)))
                dp[mask] = (dp[mask] + dp[mask|(1<<j)]) % MOD;
    }
    cout << dp[0] << '\n';

    return 0;
}
