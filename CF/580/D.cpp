#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, k;
ll a[20], g[20][20], memo[1<<20][20];

ll increase(int mask, int last, int next) {
    if (mask == 0) return a[next];
    else return a[next] + g[last][next];
}

ll solve(int mask, int last, int ate) {
    if (ate >= m) return 0;
    if (memo[mask][last] != -1)
        return memo[mask][last];

    for (int i = 0; i < n; ++i) {
        if (mask & (1<<i) == 0) 
        memo[mask][last] = max(
            memo[mask][last],
            solve(mask | (1<<i), i, ate+1) + increase(mask, last, i)
        );
    }
    return memo[mask][last];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(memo, -1, sizeof(memo));
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < k; ++i) {
        int x, y, c; cin >> x >> y >> c;
        g[x-1][y-1] = c;
    }

    cout << solve(0, 0, 0) << '\n';
    return 0;
}