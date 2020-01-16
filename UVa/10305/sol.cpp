#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &g, vector<bool> &visited, vector<int> &out) {
    if (visited[node]) return;
    visited[node] = true;
    for (int i : g[node])
        if (!visited[i]) dfs(i,g,visited,out);
    out.push_back(node);
}

void topsort(vector<vector<int>> &g) {
    vector<bool> visited(g.size());
    vector<int> out;
    for (int i=1; i<g.size(); i++)
        dfs(i,g,visited,out); 
    for (int i=out.size()-1; i>=0; i--) cout<<out[i]<<' ';
    cout<<endl;
}

int main() {
    int n,m;
    while (cin>>n>>m) {
        if (n==0 and m==0) break;
        vector<vector<int>> g(n+1);
        for (int i=0; i<m; i++) {
            int node,dest; cin>>node>>dest;
            g[node].push_back(dest);
        }
        topsort(g);
    }

    return 0;
}
