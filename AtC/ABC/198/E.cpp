#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n;
vector<bool> good, vis;
vi c, col(1e5+1);
vvi g;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;

    if (col[c[u]] == 1)
        good[u] = true;

    for (int v : g[u]) {
        ++col[c[v]];
        dfs(v);
        --col[c[v]];
    }
}

void solve() {
    good.resize(n);
    vis.resize(n);
    col[c[0]] = 1;
    dfs(0);
    for (int i = 0; i < n; ++i)
        if (good[i]) cout << i+1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    c.resize(n);
    g.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for (int i = 0; i < n-1; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    solve();

    return 0;
}