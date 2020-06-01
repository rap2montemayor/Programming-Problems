#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
const int INF = 2e9;

int n;
vi h;
vvi dp;
int solve(int idx, int prev) {
    if (idx >= n) {
        if (prev == n-1) return 0;
        else return INF;
    };
    if (dp[idx][idx-prev] != -1)
        return dp[idx][idx-prev];

    int ans = abs(h[idx] - h[prev]);
    ans = min(
        ans + solve(idx+1,idx),
        ans + solve(idx+2,idx)
    );

    dp[idx][idx-prev] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    h = vi(n);
    dp = vvi(n,vi(3,-1));
    for (int i=0; i<n; i++)
        cin>>h[i];

    cout << solve(0,0) << '\n';
    return 0;
}