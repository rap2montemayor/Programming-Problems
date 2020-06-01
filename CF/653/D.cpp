#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int INF = 2e9;
const double EPS = 1e-9;

struct flow_network {
    int n,s,t,*par;
    double **c, **f, unit;
    vi *adj;

    flow_network(int n, int s, int t) : n(n), s(s), t(t) {
        adj = new vi[n];
        par = new int[n];
        c = new double*[n];
        f = new double*[n];
        unit = 1;
        for (int i=0; i<n; ++i) {
            c[i] = new double[n];
            f[i] = new double[n];
            for (int j=0; j<n; ++j)
                c[i][j] = f[i][j] = 0;
        }
    }

    void add_edge(int u, int v, double w) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u][v] += w;
    }

    void reset_flow() {
        for (int i=0; i<n; ++i)
            memset(f[i],0,n*sizeof(double));
    }

    void set_unit(double u) {
        c[0][1] /= unit;
        unit = u;
        c[0][1] *= unit;
        reset_flow();
    }

    double res(int i, int j) {
        return c[i][j] - f[i][j];
    }

    bool bfs() {
        queue<int> q;
        q.push(this->s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (res(u,v) >= unit and par[v] == -1) {
                    par[v] = u;
                    if (v == this->t) return true;
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

    double calc_max_flow() {
        double ans=0;
        while (aug_path()) {
            double flow = INF;
            for (int u=t; u!=s; u=par[u])
                flow = min(flow,res(par[u],u));

            double delta = unit * int(flow/unit);
            for (int u=t; u!=s; u=par[u])
                f[par[u]][u] += delta, f[u][par[u]] -= delta;
            ans += delta;
        }
        return ans;
    }
};

int main() {
    int n,m,x; cin>>n>>m>>x;
    flow_network fn(n+1,0,n);
    fn.add_edge(0,1,x);

    int maxw=0;
    for (int i=0; i<m; i++) {
        int u,v,w; cin>>u>>v>>w;
        fn.add_edge(u,v,w);
        maxw = max(maxw,w);
    }
    
    double l=0, r=maxw;
    for (int i=0; i<128; i++) {
        double m = (l+r)/2;
        fn.set_unit(m);
        double flow = fn.calc_max_flow();
        double res = fn.c[0][1]-flow;
        if (res>0) r=m;
        else l=m;
    }

    cout << fixed << setprecision(6) << l*x << endl;
    return 0;
}