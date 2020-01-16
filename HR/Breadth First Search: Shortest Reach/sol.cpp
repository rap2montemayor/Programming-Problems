#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin>>q;
    while (q--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> adjList(n+1, vector<int>());
        for (int i=0; i<m; i++) {
            int u,v; cin>>u>>v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        int s; cin>>s;

        vector<int> dist(n+1,-1);
        vector<bool> visited(n+1,false);
        queue<int> bfsqueue;
        dist[s]=0;
        visited[s]=true;
        bfsqueue.push(s);

        while (!bfsqueue.empty()) {
            int current = bfsqueue.front();
            for (int i : adjList[bfsqueue.front()]) {
                if (!visited[i]) {
                    visited[i]=true;
                    dist[i] = dist[current]+6;
                    bfsqueue.push(i);
                }
            }
            bfsqueue.pop();
        }

        for (int i=1; i<=n; i++) {
            if (i==s) continue;
            cout << dist[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
