#include <bits/stdc++.h>
using namespace std;

long long n, a[3000], dp[3000][3000];
long long solve(int l, int r) {
    if (l == r) return a[l];
    if (dp[l][r] != -1) return dp[l][r];

    // assume you're always taro?
    dp[l][r] = max(
        a[l] - solve(l+1, r),
        a[r] - solve(l, r-1)
    );

    return dp[l][r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(0, n-1) << '\n';

    return 0;
}