#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
const int INF = 2e9;

int n,m,k;
vi c;
vvi p;

vvvi dp;
int solve(int idx, int prev, int colors, int current) {
    if (idx >= c.size()) return 0;
    // if (dp[idx][prev][colors] != INF)
    //      return dp[idx][prev][colors];

    // colorable
    int ans = INF;
    if (c[idx]==0) {
        for (int j=0; j<m; j++) {
            if (prev == j) {
                ans = min(
                    ans,
                    p[idx][j] + solve(idx+1, current, colors, j)
                );
            }
            else {
                ans = min(
                    ans,
                    p[idx][j] + solve(idx+1, current, colors+1, j)
                );
                if (colors+1 == k)
                    cout << ans << endl;
            }
        }
    }
    // not colorable
    else ans = solve(idx+1, current, colors, c[idx+1]);

    // dp[idx][prev][colors] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m>>k;
    c = vi(n);
    p = vvi(n, vi(m));
    // dp = vvvi(n, vvi(m, vi(m, INF)));

    for (int i=0; i<n; i++)
        cin>>c[i];

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin>>p[i][j];
    
    cout << solve(0,0,0,0) << '\n';
    return 0;
}