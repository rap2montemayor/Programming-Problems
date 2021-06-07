#include <bits/stdc++.h>
using namespace std;

int query(int t, int i, int j, int x) {
    cout << "? " << t << ' ' << i << ' '
         << j << ' ' << x << endl << flush;
    int res; cin >> res;
    return res;
}

void ans(vector<int> &v) {
    cout << "! ";
    for (int i : v)
        cout << i << ' ';
    cout << endl << flush;
}

void solve(int n) {
    // find max
    int maxi = -1;
    for (int i = 1; i <= n; i += 2) {
        if (i == n) --i;
        int res = query(1, i, i+1, n-1);
        if (res == n) maxi = i+1;
        else if (res == n-1) {
            res = query(1, i+1, i, n-1);
            if (res == n) maxi = i;
        }
        if (maxi != -1) break;
    }

    // build ans
    vector<int> v(n);
    for (int i = 1; i <= n; ++i) {
        if (i == maxi) v[i-1] = n;
        else v[i-1] = query(2, i, maxi, 1);
    }
    ans(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        solve(n);
    }
    return 0;
}