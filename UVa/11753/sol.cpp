#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;
int n, k, nums[MAXN], dp[MAXN];

int solve(int l, int r, int cur) {
    if (cur > k) return cur;
    if (l >= r) return cur;
    if (nums[l] == nums[r]) return solve(l+1, r-1, cur);
    return min(solve(l+1,r,cur+1), solve(l,r-1,cur+1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> nums[i];
        memset(dp, -1, sizeof dp);

        int ans = solve(0, n-1, 0);
        cout << "Case " << t << ": "; 
        if (ans > k) cout << "Too difficult\n";
        else if (ans == 0) cout << "Too easy\n";
        else cout << ans << '\n';
    }
    return 0;
}
