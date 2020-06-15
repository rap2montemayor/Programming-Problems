#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<bool> opt, cur;
vector<vector<int>> g;
void solve(int idx=0) {
    if (idx == g.size()) {
        int optCnt = accumulate(opt.begin(), opt.end(), 0);
        int curCnt = accumulate(cur.begin(), cur.end(), 0);
        if (curCnt > optCnt) opt = cur;
        return;
    }
    
    solve(idx+1);

    bool canTake = true;
    for (int v : g[idx]) {
        if (cur[v]) {
            canTake = false;
            break;
        }
    }
    if (canTake) {
        cur[idx] = true;
        solve(idx+1);
        cur[idx] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m; cin>>m;
    while (m--) {
        cin >> n >> k;
        g = vector<vector<int>>(n);
        while (k--) {
            int u, v; cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        opt = cur = vector<bool>(n);
        solve();

        cout << accumulate(opt.begin(), opt.end(), 0) << '\n';
        bool first = true;
        for (int i = 0; i < n; i++) {
            if (opt[i]) {
                if (first) first = false;
                else cout << ' ';
                cout << i+1;
            }
        }
        cout << '\n';
    }
    return 0;
}
