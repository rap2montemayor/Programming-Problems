#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vii;

ll nC2(ll n) {
    return n*(n-1)/2;
}

ll getSameXs(vii &polls) {
    sort(polls.begin(), polls.end());
    ll ans = 0, count = 0;

    ll prev = polls[0].first;
    for (pii &p : polls) {
        if (p.first==prev) count++;
        else {
            ans += nC2(count);
            count = 1;
            prev = p.first;
        }
    }
    ans += nC2(count);
    return ans;
}

ll getSameYs(vii &polls) {
    sort(polls.begin(),polls.end(),[](pii &first, pii &second){ return first.second < second.second;});
    ll ans = 0, count = 0;

    ll prev = polls[0].second;
    for (pii &p : polls) {
        if (p.second==prev) count++;
        else {
            ans += nC2(count);
            count = 1;
            prev = p.second;
        }
    }
    ans += nC2(count);
    return ans;
}

ll getSameXY(vii &polls) {
    sort(polls.begin(), polls.end());
    ll ans = 0, count = 0;

    pii prev = polls[0];
    for (pii &p : polls) {
        if (p==prev) count++;
        else {
            ans += nC2(count);
            count = 1;
            prev = p;
        }
    }
    ans += nC2(count);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n; cin>>n;
    vii polls(n);
    for (ll i=0; i<n; i++) {
        ll x,y; cin>>x>>y;
        polls[i] = {x,y};
    }

    cout << getSameXs(polls) + getSameYs(polls) - getSameXY(polls) << '\n';
    return 0;
}