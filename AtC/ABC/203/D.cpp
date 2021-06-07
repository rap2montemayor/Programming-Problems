#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k, a[800][800], b[801][801];

void process(int median) {
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            b[i][j] = (a[i-1][j-1] >= median) ? 1 : 0;
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
}

bool obj() {
    int good = false;
    for (int i = 0; i <= n-k; ++i) {
        for (int j = 0; j <= n-k; ++j) {
            int res = b[i][j] - b[i][j+k] - b[i+k][j]
                    + b[i+k][j+k];
            good = good or res < k*k/2+1;
        }
    }
    return good;
}

ll solve() {
    int l = 0, r = 1e9+1, m;
    while (r - l > 1) {
        m = (l+r) / 2;
        process(m);
        if (not obj()) l = m;
        else r = m;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    cout << solve() << '\n';

    return 0;
}