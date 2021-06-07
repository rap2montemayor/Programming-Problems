#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int n, m;
vvi g(2000), reach(2000, vi(2000));

void bfs() {
    queue<ii> q;
    for (int i = 0; i < n; ++i) {
        q.push({i, i});
        reach[i][i] = true;
    }

    while (not q.empty()) {
        int u = q.front().first,
            sauce = q.front().second;
        q.pop();
        
        for (int v: g[u]) {
            if (reach[sauce][v]) continue;
            reach[sauce][v] = true;
            q.push({v, sauce}); // haha
        }
    }
}

int solve() {
    bfs();
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (reach[i][j]) ++ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u-1].push_back(v-1);
    }
    cout << solve() << '\n';
    
    return 0;
}