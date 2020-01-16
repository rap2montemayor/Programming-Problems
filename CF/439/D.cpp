#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ops(ll n, vector<ll> &a, vector<ll> &b) {
    ll result=0;
    for (ll i : a)
        if (i < n) result+=n-i;
    for (ll i : b)
        if (i > n) result+=i-n;
    return result;
}

int main() {
    ll n,m; cin>>n>>m;
    vector<ll> a(n), b(m);
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<m; i++) cin>>b[i];

    ll l=0, r=1e9+7;
    while (l<r) {
        ll mid = (l+r)/ 2;
        if (ops(mid,a,b) < ops(mid+1,a,b))
            r=mid;
        else
            l=mid+1;
    }

    cout << ops(l,a,b) << endl;
    return 0;
}
