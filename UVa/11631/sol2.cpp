#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

struct graph {
    int n;
    vector<bool> vis;
    vector<vii> adj;
    graph(int n) : n(n) {
        adj = vector<vii>(n);
        vis = vector<bool>(n);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void prim(viii &res, int s = 0) {
        fill(vis.begin(),vis.end(),false);
        res.clear();

        priority_queue<ii, vii, greater<ii>> pq;
        pq.push({0, s});
        vis[s] = true;
        while (!pq.empty()) {
            int u = pq.top().second; pq.pop();
            vis[u] = true;
            for (ii p : adj[u]) {
                int v = p.first, w = p.second;
                if (v == u) continue;
                if (vis[v]) continue;
                res.push_back({w, {u, v}});
                pq.push({w, v});
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; 
    while (cin >> n >> m) {
        if (n == 0 and m == 0) break;

        int total = 0;
        graph g(n);
        for (int i = 0; i < m; i++) {
            int u, v, w; cin >> u >> v >> w;
            g.addEdge(u, v, w);
            total += w;
        }

        viii mst;
        g.prim(mst);
        int cost = 0;
        for (iii p : mst) {
            int u = p.second.first;
            int v = p.second.second;
            int w = p.first;
            cost += w;
            cout << u << ' ' << v << ' ' << w << '\n';
        }
        cout << cost << endl;
    }

    return 0;
}