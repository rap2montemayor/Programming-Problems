#include <bits/stdc++.h>
using namespace std;

long long n, k, a[100], dp[100][100001];

long long solve(int kid, int remain) {
    if (kid == n) return 0;
    if (k > accumulate(a+kid, a+n, 0)) return 0;

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << solve(0, k) << '\n';

    return 0;
}