#include <bits/stdc++.h>
using namespace std;

int n, k, a[100001], dp[100001] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    // 0 = losing, 1 = winning
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + a[j] > k) continue;
            if (dp[i] == 0) dp[i+a[j]] = 1;
        }
    }
    cout << (dp[k] == 1 ? "First\n" : "Second\n");

    return 0;
}