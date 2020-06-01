#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

struct flow_network {
    int n,s,t,*par,**c,**f;
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
        c[v][u] += w;
    }

    int res(int i, int j) {
        return c[i][j] - f[i][j];
    }

    bool bfs() {
        queue<int> q;
        q.push(this->s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (res(u,v)>0 and par[v]==-1) {
                    par[v] = u;
                    if (v==this->t) return true;
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
        int ans=0;
        while (aug_path()) {
            int flow = 1e9;
            for (int u=t; u!=s; u=par[u])
                flow = min(flow,res(par[u],u));
            for (int u=t;  u!=s; u=par[u])
                f[par[u]][u] += flow, f[u][par[u]] -= flow;
            ans += flow;
        }
        return ans;
    }

    set<int> get_min_cut() {
        set<int> cut;
        queue<int> q;
        q.push(this->s);
        cut.insert(this->s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (cut.count(v)) continue;
                if (res(u,v)==0) continue;
                cut.insert(v);
                q.push(v);
            }
        }
        return cut;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m; cin>>n>>m;
    
    while (n!=0 or m!=0) {
        flow_network fn(n+1,1,2);
        for (int i=0; i<m; i++) {
            int u,v,c; cin>>u>>v>>c;
            fn.add_edge(u,v,c);
        }
        fn.calc_max_flow();

        set<int> min_cut = fn.get_min_cut();
        for (int u : min_cut) {
            for (int v : fn.adj[u]) {
                if (min_cut.count(v)) continue;
                cout << u << ' ' << v << endl;
            }
        }
        cout << endl;
        
        cin>>n>>m;
    }
    return 0;
}
