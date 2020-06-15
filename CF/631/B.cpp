#include <bits/stdc++.h>
using namespace std;

void init(vector<vector<int>> &nextdown, vector<vector<int>> &nextright) {
    int n = nextdown.size(), m = nextdown[0].size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            nextdown[i][j] = i+1;
            nextright[i][j] = j+1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k; cin>>n>>m>>k;
    vector<vector<bool>> done(3, vector<bool>(max(n,m)+1));
    vector<vector<int>>
        queries(k, vector<int>(3)),
        grid(n, vector<int>(m)),
        nextdown(n, vector<int>(m)),
        nextright(n, vector<int>(m));
    init(nextdown, nextright);

    while (k--)
        cin>>queries[k][0]>>queries[k][1]>>queries[k][2];
    
    for (vector<int> &q : queries) {
        if (done[q[0]][q[1]]) continue;
        done[q[0]][q[1]] = true;
        q[1]--;
        if (q[0] == 1) {
            int r = q[1], a = q[2], c = 0;
            while (c < m) {
                if (grid[r][c] == 0)
                    grid[r][c] = a;
                if (r > 0)
                    nextdown[r-1][c] = nextdown[r][c];
                c = nextright[r][c];
            }
        }
        else {
            int c = q[1], a = q[2], r = 0;
            while (r < n) {
                if (grid[r][c] == 0)
                    grid[r][c] = a;
                if (c > 0)
                    nextright[r][c-1] = nextright[r][c];
                r = nextdown[r][c];
            }
        }
    }

    for (vector<int> &v : grid) {
        for (int i : v) cout << i << ' ';
        cout << endl;
    }
    return 0;
}