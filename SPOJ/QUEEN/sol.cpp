#include <bits/stdc++.h>
using namespace std;

short di[] = {-1,-1,-1,0,1,1,1,0}, dj[] = {-1,0,1,1,1,0,-1,-1};
vector<vector<short>> vis(1000, vector<short>(1000));
vector<string> grid(1000);

void reset(short n, short m) {
    for (short i = 0; i < n; ++i)
        fill(vis[i].begin(), vis[i].begin()+m, 0);
}

pair<short,short> findS(short n, short m) {
    for (short i = 0; i < n; ++i)
        for (short j = 0; j < m; ++j)
            if (grid[i][j] == 'S') return {i, j};
    return {-1, -1};
}

short moves(short n, short m) {
    queue<pair<short,short>> q;
    q.push(findS(n, m));

    short ans = -1;
    while (!q.empty()) {
        short i = q.front().first, j = q.front().second;
        short mov = vis[i][j];
        q.pop();

        for (short x=0; x<8; ++x) {
            short y = 1;
            while (++y) {
                short ii = i + di[x]*y, jj = j + dj[x]*y;
                bool valid = ii >= 0 and jj >= 0 and ii < n and jj < m;

                if (!valid || grid[ii][jj] == 'X') break;
                if (valid && grid[ii][jj] == 'F') {
                    ans = mov + 1;
                    break;
                }
                if (valid && !vis[ii][jj]) {
                    vis[ii][jj] = mov + 1;
                    q.push({ii, jj});
                }
            }
            if (ans != -1) break;
        }
        if (ans != -1) break;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    short t, n, m;
    cin>>t;
    while (t--) {
        cin>>n>>m;
        for (short i=0; i<n; ++i)
            cin>>grid[i];
        reset(n, m);
        cout << moves(n, m) << '\n';
    }
    return 0;
}