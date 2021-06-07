#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int N, M;
vvi g;

void dfs(int idx, vi &verts, vector<bool> &vis) {
    if (vis[idx]) return;
    vis[idx] = true;
    verts.push_back(idx);
    for (int v : g[idx])
        dfs(v, verts, vis);
}

bool good(int idx, int i, vi &verts, vi &pos, vi &cols) {
    for (int v : g[verts[idx]])
        if (pos[v] < idx and cols[v] == i)
            return false;
    return true;
}

long long color(int idx, vi &verts, vi &pos, vi &cols) {
    if (idx >= verts.size()) return 1;
    long long ans = 0;
    for (int i = 0; i < 3; ++i) {
        cols[verts[idx]] = i;
        if (good(idx, i, verts, pos, cols))
            ans += color(idx+1, verts, pos, cols);
    }
    return ans;
}

long long solve() {
    long long ans = 0;
    vector<bool> vis(N);
    vi pos(N), cols(N), verts;
    for (int i = 0; i < N; ++i) {
        if (not vis[i]) {
            verts.resize(0);
            dfs(i, verts, vis);
            for (int i = 0; i < verts.size(); ++i)
                pos[verts[i]] = i;
            if (ans) ans *= 3*color(1, verts, pos, cols);
            else ans += 3*color(1, verts, pos, cols);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    g.resize(N);
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << solve() << '\n';
    return 0;
}