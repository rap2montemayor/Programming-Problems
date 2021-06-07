#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

ll n, a[100000];

unordered_map<ll, ll> cnt, isum;
ll solve() {
    cnt.clear(), isum.clear();
    ll ans = 0, add = 0;
    for (ll i = 0; i < n; ++i) {
        if (cnt[a[i]] > 0)
            add += cnt[a[i]] + isum[a[i]];
        isum[a[i]] += i;
        ++cnt[a[i]];
        ans += add;
    }
 
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll t; cin >> t;
    while (t--) {
        cin >> n;
        for (ll i = 0; i < n; ++i)
            cin >> a[i];
        cout << solve() << '\n';
    }
    return 0;
}