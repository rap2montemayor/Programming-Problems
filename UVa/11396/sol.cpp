#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> &g) {
    vector<int> side(g.size(),-1);
    queue<int> q;
    q.push(1);
    side[1]=0;
    while (!q.empty()) {
        for (int i : g[q.front()]) {
            if (side[i]==-1) {
                q.push(i);
                side[i]=side[q.front()]^1;
            }
            if (side[i]==side[q.front()])
                return false;
        }
        q.pop();
    }

    return true;
}

bool allDegree3(vector<vector<int>> &g) {
    for (int i=1; i<g.size(); i++)
        if (g[i].size()!=3) return false;
    return true;
}

int main() {
    int n;
    while (cin>>n) {
        if (n==0) break;
        vector<vector<int>> g(n+1);
        int a,b;
        while (cin>>a>>b) {
            if (a==0 and b==0) break;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        if (isBipartite(g)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
