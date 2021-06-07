#include <bits/stdc++.h>
using namespace std;

long long n, a[400], sums[400][400], cost[400][400];

void calcsums() {
    memset(sums, 0, sizeof(sums));
    for (int i = n-1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            if (i == j) sums[i][j] = a[i];
            else sums[i][j] = sums[i+1][j] + sums[i][i];
        }
    }
}

long long solve(int l, int r) {
    if (cost[l][r] != 1e18) return cost[l][r];
    if (l == r) cost[l][r] = 0;
    for (int i = l; i < r; ++i)
        cost[l][r] = min(cost[l][r], sums[l][r] + solve(l, i) + solve(i+1, r));
    return cost[l][r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cost[i][j] = 1e18;
        cin >> a[i];
    }
    calcsums();
    cout << solve(0, n-1) << '\n';

    return 0;
}