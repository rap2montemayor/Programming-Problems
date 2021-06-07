#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n;
vvi g;
set<ii> cuts;
vi deg;
int get_cuts(int u, int par, int root = true) {
    if (deg[u] == 1 and not root) return 0;
    int ans = 0;
    for (int v : g[u]) {
        if (v == par or cuts.count({u, v}) or cuts.count({v, u}))
            continue;
        ans += get_cuts(v, u, false);
    }

    for (int v : g[u]) {
        if (v == par or cuts.count({u, v}) or cuts.count({v, u}))
            continue;
        if (deg[v] >= 3) {
            ++ans;
            cuts.insert({u, v});
            --deg[u], --deg[v];
        }
    }

    for (int v : g[u]) {
        if (v == par or cuts.count({u, v}) or cuts.count({v, u}))
            continue;
        if ((not root and deg[u] <= 3) or (root and deg[u] <= 2))
            break;
        ++ans;
        cuts.insert({u, v});
        --deg[u], --deg[v];
    }

    return ans;
}

void get_deg() {
    deg.resize(n);
    for (int i = 0; i < n; ++i)
        deg[i] = g[i].size();
}

struct uf {
    vi p;
    uf(int n) : p(n, -1) {}
    
    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }

    bool unite(int x, int y) {
        int xp = find(x), yp = find(y);
        if (xp == yp) return false;
        if (p[xp] > p[yp]) swap(xp, yp);
        p[xp] += p[yp];
        p[yp] = xp;
        return true;
    }
};

void get_comps(int u, int par, uf &comps) {
    for (int v : g[u]) {
        if (v == par or cuts.count({u, v}) or cuts.count({v, u}))
            continue;
        comps.unite(u, v);
        get_comps(v, u, comps);
    }
}

set<ii> get_adds() {
    uf comps(n);
    for (int i = 0; i < n; ++i)
        if (comps.find(i) == i)
            get_comps(i, i, comps);

    set<ii> adds;
    for (int u = 0; u < n; ++u) {
        for (int v = u+1; v < n; ++v) {
            if (deg[u] > 1) break;
            if (deg[v] > 1) continue;
            if (comps.unite(u, v)) {
                ++deg[u], ++deg[v];
                adds.insert({u, v});
            }
        }
    }
    return adds;
}

void solve() {
    get_deg();
    int c = get_cuts(0, 0);
    set<ii> adds = get_adds();

    cout << c << "\n";
    auto add_itr = adds.begin(), cut_itr = cuts.begin();
    for (int i = 0; i < c; ++i) {
        ii add = *add_itr, cut = *cut_itr;
        cout << cut.first+1 << ' ' << cut.second+1 << ' '
             << add.first+1 << ' ' << add.second+1 << '\n';
        ++add_itr, ++cut_itr;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >>t;
    while (t--) {
        cin >> n;
        g.clear();
        cuts.clear();
        deg.clear();

        g.resize(n);
        for (int i = 0; i < n-1; ++i) {
            int a, b; cin >> a >> b;
            --a, --b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        solve();
    }

    return 0;
}