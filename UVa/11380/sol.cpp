#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int INF = 1e9;

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
            par[u]=-1;
        par[s]=s;
        return bfs();
    }

    int calc_max_flow() {
        int ans=0;
        while (aug_path()) {
            int flow=INF;
            for (int u=t; u!=s; u=par[u])
                flow=min(flow,res(par[u],u));
            for (int u=t; u!=s; u=par[u])
                f[par[u]][u]+=flow, f[u][par[u]]-=flow;
            ans+=flow;
        }
        return ans;
    }
};

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int getIdx(int i, int j, int x, int y) {
    return i*y + j + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int x,y,p;
    while (cin>>x>>y>>p) {
        vector<string> grid(x);
        for (int i=0; i<x; ++i)
            cin>>grid[i];

        map<char,int> weight;
        weight['.'] = weight['*'] = 1;
        weight['@'] = weight['#'] = INF;
        flow_network fn(x*y*2+2,0,x*y*2+1);
        for (int i=0; i<x; ++i) {
            for (int j=0; j<y; ++j) {
                int uin = getIdx(i,j,x,y),
                    uout = uin+x*y;
                if (grid[i][j] == '~') continue;
                if (grid[i][j] == '*') fn.add_edge(0,uin,1);
                if (grid[i][j] == '#') fn.add_edge(uout,x*y*2+1,p);
                fn.add_edge(uin,uout,weight[grid[i][j]]);

                for (int k=0; k<4; ++k) {
                    bool valid = i+dx[k]>=0 and i+dx[k]<x and
                                 j+dy[k]>=0 and j+dy[k]<y and
                                 grid[i+dx[k]][j+dy[k]]!='~' and
                                 grid[i+dx[k]][j+dy[k]]!='*';
                    if (valid) {
                        int v = getIdx(i+dx[k],j+dy[k],x,y);
                        fn.add_edge(uout,v,INF);
                    }
                }
            }
        }

        cout << fn.calc_max_flow() << endl;
    }
    
    return 0;
}
