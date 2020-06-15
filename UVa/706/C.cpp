#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int MAXN = 1e5;
ll n, c[MAXN], dp[MAXN][2];
string normal[MAXN], reversed[MAXN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    memset(dp, -1, sizeof dp);
    for (ll i=0; i<n; i++) cin>>c[i];
    for (ll i=0; i<n; i++) {
        cin>>normal[i];
        reversed[i] = normal[i];
        reverse(reversed[i].begin(), reversed[i].end());
    }

    dp[0][0] = 0;
    dp[0][1] = c[0];
    for (ll i=1; i<n; i++) {
        for (ll j=0; j<2; j++) {
            string &cur = j ? reversed[i] : normal[i];
            ll ans1 = -1, ans2 = -1;
            if (cur >= normal[i-1])
                ans1 = dp[i-1][0];
            if (cur >= reversed[i-1])
                ans2 = dp[i-1][1];
            if (j) {
                if (ans1 != -1) ans1 += c[i];
                if (ans2 != -1) ans2 += c[i];
            }

            if (ans1 == -1 or ans2 == -1)
                dp[i][j] = max(ans1, ans2);
            else
                dp[i][j] = min(ans1, ans2);
        }
    }

 
    if (dp[n-1][0] == -1 or dp[n-1][1] == -1)
        cout << max(dp[n-1][0], dp[n-1][1]) << '\n';
    else
        cout << min(dp[n-1][0], dp[n-1][1]) << '\n';
    return 0;
}
