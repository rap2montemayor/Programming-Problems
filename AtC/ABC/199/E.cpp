#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
ll n, m;
vi x(100), y(100), z(100);

ll cntmask(ll n) {
    ll ans = 0;
    while (n) {
        ans += n%2;
        n /= 2;
    }
    return ans;
}

bool checkrule(ll mask, ll rule) {
    ll cnt = 0;
    for (ll i = 0; i < y[rule]; ++i)
        if (mask & (1<<i))
            ++cnt;
    return cnt <= z[rule];
}

bool check(ll mask) {
    ll elems = cntmask(mask);
    for (ll i = 0; i < m; ++i) {
        if (x[i] != elems) continue;
        if (not checkrule(mask, i)) return false;
    }
    return true;
}

ll solve() {
    vi memo(1<<n);
    memo[0] = 1;

    queue<ll> q;
    q.push(0);

    while (not q.empty()) {
        ll mask = q.front();
        q.pop();
        
        for (ll i = 0; i < n; ++i) {
            if (mask & (1<<i)) continue;
            if (check(mask + (1<<i))) {
                memo[mask + (1<<i)] += memo[mask];
                if (memo[mask + (1<<i)] == memo[mask])
                    q.push(mask + (1<<i));
            }
        }
    }

    return memo[(1<<n) - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (ll i = 0; i < m; ++i)
        cin >> x[i] >> y[i] >> z[i];

    cout << solve() << '\n';
    return 0;
}