#include <bits/stdc++.h>
using namespace std;

int find_min(int n, vector<int> &ints) {
    int ans = 0;
    for (int i = 1; i < n; ++i)
        if (ints[i] < ints[ans]) ans = i;
    return ans;
}

void solve(int n, vector<int> &ints) {
    int mn = find_min(n, ints),
        idx = 1,
        p[] = {int(1e9+7), int(1e9+9)};
    vector<vector<int>> ops;

    for (int i = 0; i < n; ++i) {
        idx = (idx+1) % 2;
        if (i == mn) continue;
        ops.push_back({mn+1, i+1, ints[mn], p[idx]});
        ints[i] = p[idx];
    }

    cout << ops.size() << '\n';
    for (vector<int> &v : ops) {
        for (int i : v) cout << i << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> ints(n);
        for (int i = 0; i < n; ++i)
            cin >> ints[i];
        solve(n, ints);
    }

    return 0;
}