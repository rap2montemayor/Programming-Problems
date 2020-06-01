#include <bits/stdc++.h>
using namespace std;

int n;
double p[3000], dp[3001][3001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i=0; i<=3000; i++)
        for (int j=0; j<=3000; j++)
            dp[i][j] = 0;

    cin>>n;
    for (int i=0; i<n; i++)
        cin>>p[i];
    
    for (int idx=0; idx<n; idx++) {
        for (int heads=0; heads<=n; heads++) {
            if (idx==0) {
                if (heads==0) dp[idx][heads] = 1-p[idx];
                else if (heads==1) dp[idx][heads] = p[idx];
            }
            else {
                dp[idx][heads] += dp[idx-1][heads] * (1-p[idx]);
                if (heads > 0)
                    dp[idx][heads] += dp[idx-1][heads-1] * p[idx];
            }
        }
    }

    double ans=0;
    for (int heads=n/2+1; heads<=n; heads++)
        ans += dp[n-1][heads];
    
    cout << fixed << setprecision(10);
    cout << ans << '\n';
    return 0;
}