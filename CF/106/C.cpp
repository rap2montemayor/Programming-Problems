#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n,m;
vi a,b,c,d;
vvvi dp;

int solve(int idx, int dough, int stuffing, int depth) {
    if (idx >= a.size()) return 0;
    if (dp[idx][dough][stuffing] != -1) return dp[idx][dough][stuffing];

    int ans = solve(idx+1, dough, 0, depth+1);;
    if (dough+c[idx] <= n and stuffing+b[idx] <= a[idx])
        ans = max( ans, d[idx] + solve(idx, dough+c[idx], stuffing+b[idx], depth+1) );

    dp[idx][dough][stuffing] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;
    a = vi(m+1,0);
    b = vi(m+1,0);
    c = vi(m+1,0);
    d = vi(m+1,0);
    cin>>c[0]>>d[0];

    for (int i=1; i<=m; i++)
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    int maxStuffing=0;
    for (int i : c)
        maxStuffing = max(maxStuffing,i+1);
    for (int i : a)
        maxStuffing = max(maxStuffing,i+1);

    dp = vvvi(m+1,vvi(n+1,vi(maxStuffing,-1)));
    cout << solve(0,0,0,0) << '\n';
    return 0;
}