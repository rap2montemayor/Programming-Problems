#include <bits/stdc++.h>
using namespace std;

int n, a[100], total=0, dp[100][100001];

int solve(int idx, int t1) {
    int t2 = total - t1;
    if (idx == n) return max(t1, t2);
    if (dp[idx][t1] != 1e9) return dp[idx][t1];
    dp[idx][t1] = min(
        solve(idx+1, t1),
        solve(idx+1, t1-a[idx])
    );
    return dp[idx][t1];
}

void prep() {
    total = accumulate(a, a+n, 0);
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j <= 100000; ++j)
            dp[i][j] = 1e9;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    prep();
    cout << solve(0, total) << '\n';
    
    return 0;
}