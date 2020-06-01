#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

typedef pair<int,ii> iii;
typedef vector<iii> viii;

struct graph {
    vvii adj;
    graph(int n) {
        adj = vvii(n);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vii mst(int s = 0) {
        priority_queue<iii, viii, greater<iii>> pq;
        vector<bool> vis(adj.size());
        vii res(adj.size()); // parent pointer representation

        pq.push({0, {s, s}});
        while (!pq.empty()) {
            int w = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            
            if (vis[v]) continue;
            vis[v] = true;
            res[v] = {u, w};
            for (ii &edge : adj[v]) {
                int next = edge.first;
                int w = edge.second;
                if (!vis[next])
                    pq.push({w, {v, next}});
            }
        }

        return res;
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

        vii mst = g.mst();
        int cost = 0;
        for (ii &p : mst)
            cost += p.second;
        cout << total - cost << '\n';
    }

    return 0;
}