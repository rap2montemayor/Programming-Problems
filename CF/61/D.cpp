#include <bits/stdc++.h>
using namespace std;

long long dfs(int node, vector<vector<vector<int>>> &cities, vector<bool> &visited) {
    visited[node]=true;

    long long travel=0;
    for (int i=0; i<cities[node].size(); i++) {
        long long add=0;
        if (!visited[cities[node][i][0]]) {
            add=dfs(cities[node][i][0],cities,visited);
            add+=cities[node][i][1];
        }
        if (i!=cities[node].size()-1) add*=2;
        travel+=add;
    }
    return travel;
}

int main() {
    int n; scanf("%d",&n);
    vector<vector<vector<int>>> cities(n+1);
    vector<bool> visited(n+1);
    visited[0]=true;

    for (int i=0; i<n-1; i++) {
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        cities[x].push_back({y,w});
        cities[y].push_back({x,w});
    }

    cout << dfs(1,cities,visited) << endl;
    return 0;
}
