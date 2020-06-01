#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n,m;
vi dp;
vvi graph;
int solve(int node) {
    if (dp[node] != -1) return dp[node];

    int ans=0;
    for (int i : graph[node]) {
        ans = max(
            ans,
            1 + solve(i)
        );
    }

    dp[node] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;
    dp = vi(n+1, -1);
    graph = vvi(n+1);
    for (int i=0; i<m; i++) {
        int x,y; cin>>x>>y;
        graph[x].push_back(y);
    }

    for (int i=1; i<=n; i++)
        solve(i);
    
    int ans=0;
    for (int i : dp)
        ans = max(ans, i);
    cout << ans << '\n';
    return 0;
}