#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; cin>>n>>m;
    vector<int> ans(n+1), nxt(n+1);
    iota(nxt.begin(), nxt.end(), 1);

    while (m--) {
        int l, r, x; cin>>l>>r>>x;
        while (l <= r) {
            if (ans[l] == 0 and l != x)
                ans[l] = x;
            int tmp = l;
            l = nxt[l];
            if (tmp < x)
                nxt[tmp] = x;
            else
                nxt[tmp] = nxt[r];
        }
        nxt[x] = nxt[r];
    }

    for (int i=1; i<=n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}