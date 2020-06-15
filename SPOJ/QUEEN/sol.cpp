#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int di[] = {-1,-1,-1,0,1,1,1,0}, dj[] = {-1,0,1,1,1,0,-1,-1};
vector<vector<int>> vis(1000, vector<int>(1000));
vector<string> grid(1000);

int INF = 2e9;
void reset() {
    for (int i = 0; i < n; ++i)
        fill(vis[i].begin(), vis[i].begin()+m, INF);
}

pair<int,int> findS() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j] == 'S') return {i, j};
    return {-1, -1};
}

int moves() {
    queue<pair<int,int>> q;
    pair<int,int> start = findS();
    vis[start.first][start.second] = 0;
    q.push(findS());

    int ans = -1;
    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        int mov = vis[i][j];
        q.pop();

        if (grid[i][j] == 'F') {
            ans = mov;
            break;
        }

        for (int x=0; x<8; ++x) {
            int y = 0;
            while (++y) {
                int ii = i + di[x]*y, jj = j + dj[x]*y;
                bool valid = ii >= 0 and jj >= 0 and ii < n and jj < m;

                if (!valid || grid[ii][jj] == 'X') break;
                if (valid and mov+1 < vis[ii][jj]) {
                    vis[ii][jj] = mov + 1;
                    q.push({ii, jj});
                }
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>t;
    while (t--) {
        cin>>n>>m;
        for (int i=0; i<n; ++i)
            cin>>grid[i];
        reset();
        cout << moves() << '\n';
    }
    return 0;
}