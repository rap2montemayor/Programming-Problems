#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll h,w,dp[1000][1000];
const ll MOD = 1e9+7;
char grid[1000][1000];

ll solve(int i, int j) {
    if (i>=h or j>=w) return 0;
    if (i==h-1 and j==w-1) return 1;
    if (grid[i][j] == '#') return 0;
    if (dp[i][j] != -1) return dp[i][j];

    dp[i][j] = (solve(i+1, j) + solve(i, j+1))%MOD;
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(dp,-1,sizeof dp);
    cin>>h>>w;
    for (int i=0; i<h; i++)
        for (int j=0; j<w; j++)
            cin>>grid[i][j];

    cout << solve(0,0) << '\n';
    return 0;
}