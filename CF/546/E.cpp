#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int INF = 2e9;

struct flow_network {
    int n, s, t, *par, **c, **f;
    vi *adj;
    
    flow_network(int n, int s, int t) : n(n), s(s), t(t) {
        adj = new vi[n];
        par = new int[n];
        c = new int*[n];
        f = new int*[n];
        for (int i=0; i<n; ++i) {
            c[i] = new int[n];
            f[i] = new int[n];
            for (int j=0; j<n; ++j)
                c[i][j] = f[i][j] = 0;
        }
    }

    void add_edge(int u, int v, int w) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u][v] += w;
    }

    int res(int i, int j) {
        return c[i][j] - f[i][j];
    }

    bool bfs() {
        queue<int> q;
        q.push(this->s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (res(u,v) > 0 and par[v] == -1) {
                    par[v] = u;
                    if (v == this->t)
                    return true;
                    q.push(v);
                }
            }
        }
        return false;
    }

    bool aug_path() {
        for (int u=0; u<n; ++u)
            par[u] = -1;
        par[s] = s;
        return bfs();
    }

    int calc_max_flow() {
        int ans = 0;
        while (aug_path()) {
            int flow = INF;
            for (int u=t; u!=s; u=par[u])
                flow = min(flow, res(par[u],u));
            for (int u=t; u!=s; u=par[u])
                f[par[u]][u] += flow, f[u][par[u]] -= flow;
            ans += flow;
        }
        return ans;
    }
};

bool isCorrect(flow_network &fn, vi &a, vi &b) {
    int n = a.size();
    bool correct = true;
    for (int i=1; i<=n; ++i) {
        int sum1=0, sum2=0;
        for (int j=1; j<=n; ++j) {
            sum1 += fn.f[i][j+n];
            sum2 += fn.f[j][i+n];
        }
        if (sum1 != a[i-1] or sum2 != b[i-1]) {
            correct = false;
            break;
        }
    }
    return correct;
}

int main() {
    int n, m; cin>>n>>m;
    vi a(n), b(n);
    flow_network fn(n*2+2, 0, n*2+1);
    for (int i=0; i<n; ++i) cin>>a[i];
    for (int i=0; i<n; ++i) cin>>b[i];
    
    for (int i=0; i<n; ++i) {
        fn.add_edge(0,i+1,a[i]);
        fn.add_edge(n+i+1,n*2+1,b[i]);
        fn.add_edge(i+1,n+i+1,INF);
    }
    for (int i=0; i<m; ++i) {
        int u, v; cin>>u>>v;
        fn.add_edge(u,n+v,INF);
        fn.add_edge(v,n+u,INF);
    }

    fn.calc_max_flow();

    if (isCorrect(fn,a,b)) {
        cout << "YES\n";
        for (int i=1; i<=n; ++i) {
            for (int j=n+1; j<=n*2; ++j)
                cout << fn.f[i][j] << ' ';
            cout << '\n';
        }
    }
    else cout << "NO\n";
    
    return 0;
}
