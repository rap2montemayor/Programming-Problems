#include <bits/stdc++.h>
using namespace std;

int n,m; 
vector<string> bitmap(182);
vector<vector<int>> dists(182, vector<int>(182,200));
vector<vector<bool>> vis(182, vector<bool>(182,200));
void bfs() {
    queue<vector<int>> q;

    int di[] = {-1,0,1,0};
    int dj[] = {0,1,0,-1};

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (bitmap[i][j]=='1')
                q.push({i,j,0});

    while (!q.empty()) {
        int i = q.front()[0];
        int j = q.front()[1];
        int dist = q.front()[2];
        dists[i][j] = dist;
        vis[i][j] = true;
        q.pop();
        if (dists[i][j] < dist) continue;
        for (int x=0; x<4; ++x) {
            int ni = i+di[x], nj = j+dj[x];
            bool valid = ni >= 0 and ni < n and nj >= 0 and nj < m;
            if (valid and bitmap[ni][nj]=='0' and !vis[ni][nj]) {
                vis[ni][nj]=true;
                q.push({ni,nj,dist+1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;
    while (t--) {
        cin>>n>>m;
        for (int i=0; i<n; ++i) {
            cin>>bitmap[i];
            fill(dists[i].begin(),dists[i].begin()+m,200);
            fill(vis[i].begin(),vis[i].begin()+m,false);
        }
        
        bfs();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j)
                cout << dists[i][j] << ' ';
            cout << '\n';
        }
    }
    return 0;
}