#include <bits/stdc++.h>
using namespace std;
 
char di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1}, 
    diagi[] = {-1, -1, 1, 1}, diagj[] = {-1, 1, 1, -1},
    dirs[] = {'D', 'R', 'U', 'L'};
bool vis[7][7], a[4];
string s;

bool valid(char i, char j) {
    return i >= 0 and i < 7
        and j >= 0 and j < 7
        and not vis[i][j];
}

bool edge(char i, char j) {
	return i == 0 or j == 0 or i == 6 or j == 6;
}

bool hastunnel(char curi, char curj) {
    char i, j, x, y, taken;
    for (y = 0; y < 4; ++y) {
        i = curi + diagi[y], j = curj + diagj[y], taken = 0;
        if (not valid(i, j) or edge(i, j)) continue;

        for (x = 0; x < 4; ++x)
            taken += vis[i+di[x]][j+dj[x]];
        if (taken == 3) return true;
    }

    return false;
}

bool prune(char step, char i, char j) {
    for (char x = 0; x < 4; ++x)
        a[x] = valid(i + di[x], j + dj[x]);

    return (a[0] and !a[1] and a[2] and !a[3])
        or (!a[0] and a[1] and !a[2] and a[3])
        or (i == 6 and j == 0) or hastunnel(i, j);
}
 
int solve(char step, char i, char j) {
    if (step == 48) return 1;
    if (prune(step, i, j)) return 0;

    int ans = 0;
    char nxti, nxtj, x;
    for (x = 0; x < 4; ++x) {
        if (s[step] != '?' and s[step] != dirs[x]) continue;
        nxti = i + di[x], nxtj = j + dj[x];
        if (not valid(nxti, nxtj)) continue;
        vis[nxti][nxtj] = 1;
        ans += solve(step+1, nxti, nxtj);
        vis[nxti][nxtj] = 0;
    }

    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(vis, 0, sizeof(vis));
    memset(a, 0, sizeof(a));
    vis[0][0] = true;

    cin >> s;
    cout << solve(0, 0, 0) << '\n';

    return 0;
}
