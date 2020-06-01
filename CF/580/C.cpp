#include <bits/stdc++.h>
using namespace std;

int countRestaurants(vector<vector<int>> &g, vector<int> &a, int m) {
    queue<pair<int,int>> q;
    vector<bool> vis(g.size());
    q.push({0,a[0]});
    vis[0] = true;

    int res = 0;
    while (!q.empty()) {
        int node = q.front().first;
        int cats = q.front().second;
        q.pop();

        if (g[node].size() == 1 and node != 0) res++;
        for (int next : g[node]) {
            if (vis[next] or cats + a[next] > m) continue;

            if (a[next] == 0) q.push({next, 0});
            else q.push({next, cats+a[next]});
            vis[next] = true;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,m; cin>>n>>m;
    vector<vector<int>> g(n);
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=0; i<n-1; i++) {
        int x,y; cin>>x>>y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout << countRestaurants(g, a, m) << '\n';
    return 0;
}