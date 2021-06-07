#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll jump[20], cnt[20], step[20];
void init() {
    cnt[1] = 9, jump[1] = 1, step[1] = 1;
    for (ll i = 2; i < 20; ++i) {
        step[i] = step[i-1] * 10;
        cnt[i] = cnt[i-1] * 10;
        jump[i] = (i-1) * cnt[i-1] + jump[i-1];
    }
}

ll solve(ll n) {
    ll idx = 0, digit, cur=1;
    for (digit = 1; digit < 20; ++digit) {
        if (jump[digit] > n) break;
        else idx = jump[digit];
    }
    cur = step[--digit];

    for (ll i = digit; i >= 1; --i) {
        while (idx + step[i]*digit <= n) {
            idx += step[i]*digit;
            cur += step[i];
        }
    }

    for (ll i = 0; i < digit - (n-idx+1); ++i)
        cur /= 10;

    return cur%10;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    init();
    int q; cin >> q;
    while (q--) {
        ll n; cin >> n;
        cout << solve(n) << '\n';
    }

    return 0;
}