#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
vi p, depths;
void process(int u=0, int d=0) {
    depths[u] = d;
    for (int v: g[u])
        process(v, d+1);
}

void solve() {
    process();
    int q; cin >> q;
    while (q--) {
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    g.resize(n);
    p.resize(n);
    depths.resize(n);
    for (int i = 1; i < n; ++i) {
        int v; cin >> v;
        --v;
        p[i] = v;
        g[v].push_back(i);
    }

    solve();
    
    return 0;
}