#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll dp[31][31][31];
void init() {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 30; ++i)
        dp[1][i][1] = 1, dp[i][1][1] = i;
    for (int i = 2; i <= 30; ++i)
        for (int j = 2; j <= 30; ++j)
            dp[i][j][1] = dp[i-1][j][1] + dp[i][j-1][1];
    for (int i = 1; i <= 30; ++i) {
        for (int j = 1; j <= 30; ++j) {
            for (int k = 1; k <= j; ++k)
                dp[i][j][k] = dp[i][j][k-1] + dp[i][j-k+1][1];
        }
    }
}

void solve(ll a, ll b, ll k) {
    string ans = "";
    ll idx = 1, moves;
    while (a > 0 and idx <= k) {
        moves = 0;
        while (moves < b and idx + dp[a][b][moves+1] <= k) {
            ++moves;
            ans.push_back('b');
        }
        idx += dp[a][b][moves];
        ans.push_back('a');
        b -= moves, --a;
    }
    for (int i = 0; i < b; ++i)
        ans.push_back('b');

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll a, b, k;
    cin >> a >> b >> k;
    init();
    solve(a, b, k);
    
    return 0;
}