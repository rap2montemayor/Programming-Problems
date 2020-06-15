#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<string> maze;
vector<vector<bool>> vis;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
void dfs(int i, int j) {
    vis[i][j] = true;
    for (int x = 0; x < 4; x++) {
        int ii = i + di[x];
        int jj = j + dj[x];
        bool valid = ii >= 0 and ii < n and jj >= 0 and jj < m;
        if (valid and maze[ii][jj] != '#' and !vis[ii][jj])
            dfs(ii, jj);
    }

    if (k > 0) {
        k--;
        maze[i][j] = 'X';
    }
}

pair<int, int> getFirstOpen() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (maze[i][j] == '.')
                return {i, j};
    return {-1, -1};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    vis = vector<vector<bool>>(n, vector<bool>(m));
    maze = vector<string>(n);
    for (int i = 0; i < n; i++)
        cin >> maze[i];

    pair<int, int> ij = getFirstOpen();
    dfs(ij.first, ij.second);

    for (string s : maze)
        cout << s << '\n';
    return 0;
}