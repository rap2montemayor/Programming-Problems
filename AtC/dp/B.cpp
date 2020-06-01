#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin>>n>>k;
    int h[n], dp[n] = {0};
    for (int i=0; i<n; ++i) cin>>h[i];
    for (int i=0; i<n-1; ++i) dp[i] = 2e9;
    for (int i=n-2; i>=0; i--)
        for (int j=1; j<=k and i+j<n; j++)
            dp[i] = min(dp[i], abs(h[i]-h[i+j]) + dp[i+j]);
    cout << dp[0] << '\n';

    return 0;
}