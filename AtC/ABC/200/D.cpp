#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n;
vi a(200);

vi res1, res2;
void dfs(int idx, int sum, vi &cur, vector<vi> &seqs) {
    if (not res1.empty()) return;
    if (idx >= n) {
        if (sum == -1) return;
        if (seqs[sum].empty()) seqs[sum] = cur;
        else {
            res1 = cur;
            res2 = seqs[sum];
        }
        return;
    }

    dfs(idx+1, sum, cur, seqs);

    bool wasneg = false;
    if (sum == -1) {
        sum = 0;
        wasneg = true;
    }
    cur.push_back(idx+1);
    dfs(idx+1, (sum + a[idx]) % 200, cur, seqs);
    cur.pop_back();
    if (wasneg) sum = -1;
}

void solve() {
    vector<vi> seqs(200);
    vi cur;
    dfs(0, -1, cur, seqs);
    
    if (res1.empty()) cout << "NO\n";
    else {
        cout << "yeS\n";

        cout << res1.size() << ' ';
        for (int i : res1)
            cout << i << ' ';
        cout << '\n';

        cout << res2.size() << ' ';
        for (int i : res2)
            cout << i << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= 200;
    }
    solve();

    return 0;
}